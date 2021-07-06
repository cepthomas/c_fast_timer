
#include <windows.h>
#include "stopwatch.h"
#include "ftimer.h"


//---------------- Private Declarations ------------------//

/// Registered client callback.
static ftimer_InterruptFunc_t p_interrupt_func = NULL;

/// Requested pulse period in msec.
static unsigned p_period = 0;

/// Resolution of p_period.
static unsigned p_ft_res = 10;

/// System mmtimer resource.
static MMRESULT p_sys_handle = -1;

/// System mmtimer callback. Ignore all args.
static void CALLBACK p_TimerCallback(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2);

/// Where we are in p_period.
static double p_current_msec = 0.0;

/// <summary>Stopwatch support.</summary>
long p_last_usec = -1;

/// Module status.
static int p_status = 0;

/// Module status.
static bool p_running = false;


//---------------- Public API Implementation -------------//

//--------------------------------------------------------//
int ftimer_Init(ftimer_InterruptFunc_t fp, unsigned ft_res)
{
    if(fp == NULL || ft_res < 1)
    {
        p_status = 1;
    }
    else
    {
        int swst = stopwatch_Init();
        if(swst != 0)
        {
            p_status = 2;
        }
        else
        {
            p_interrupt_func = fp;
            p_ft_res = ft_res;
        }
    }

    return p_status;
}

//--------------------------------------------------------//
int ftimer_Run(unsigned period)
{
    if(p_status == 0)
    {
        p_period = period;

        if(period > 0)
        {
            // Clean up if already running.
            if(p_sys_handle >= 0)
            {
                timeKillEvent(p_sys_handle);
            }

            p_running = true;
            p_sys_handle = timeSetEvent(p_ft_res, 0, p_TimerCallback, 0, TIME_PERIODIC);
        }
        else
        {
            if(p_sys_handle >= 0)
            {
                timeKillEvent(p_sys_handle); //check return result != TIMERR_NOERROR
            }
            p_sys_handle = -1;
            p_status = 3;
            p_running = false;
        }
    }

    return p_status;
}

//--------------------------------------------------------//
int ftimer_Destroy(void)
{
    if(p_sys_handle >= 0)
    {
        timeKillEvent(p_sys_handle);
    }

    p_sys_handle = -1;
    p_period = 0;
    p_interrupt_func = NULL;
    p_status = 0;
    p_running = false;

    return p_status;
}

//--------------------------------------------------------//
// long ftimer_CurrentUsec(void)
// {
//     long usec = 0;

//     if(p_status == 0)
//     {
//         usec = stopwatch_ElapsedMicroseconds();   
//     }

//     return usec;
// }


//---------------- Private Implementation -------------//

//--------------------------------------------------------//
void CALLBACK p_TimerCallback(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
    if(p_running)
    {
        if(p_last_usec != -1)
        {
            // When are we?
            long t = stopwatch_ElapsedMicroseconds(); // snap
            double msec = (t - p_last_usec) * 1000.0;
            p_last_usec = t;

            // Check for expirations.
            p_current_msec += msec;

            const double ALLOWANCE = 0.5; // msec

            if((p_period - p_current_msec) < ALLOWANCE)
            {
                p_current_msec = 0.0;
                if(p_interrupt_func != NULL)
                {
                    p_interrupt_func();
                }
            }
        }
        else
        {
            // Starting.
            p_last_usec = stopwatch_ElapsedMicroseconds();
        }
    }
}
