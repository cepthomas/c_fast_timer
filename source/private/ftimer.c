
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



static int _counter = 0; //TODO


//---------------- Public API Implementation -------------//

//--------------------------------------------------------//
int ftimer_Init(ftimer_InterruptFunc_t fp, unsigned ft_res)
{
    int stat = 0;

    p_interrupt_func = fp;
    p_ft_res = ft_res;

    // if(!Stopwatch.IsHighResolution)
    // {
    //     throw new Exception("High res performance counter is not available.");
    // }


    return stat;
}

//--------------------------------------------------------//
int ftimer_Run(unsigned period)
{
    int stat = 0;

    p_period = period;

    if(period > 0)
    {
        // Clean up if already running.
        if(p_sys_handle >= 0)
        {
            timeKillEvent(p_sys_handle);
        }

        p_sys_handle = timeSetEvent(p_ft_res, 0, p_TimerCallback, 0, TIME_PERIODIC);
    }
    else
    {
        if(p_sys_handle >= 0)
        {
            timeKillEvent(p_sys_handle);
        }
        p_sys_handle = -1;

        //check return result != TIMERR_NOERROR
    }

    return stat;
}

//--------------------------------------------------------//
int ftimer_Destroy(void)
{
    int stat = 0;

    if(p_sys_handle >= 0)
    {
        timeKillEvent(p_sys_handle);
    }

    p_sys_handle = -1;
    p_period = 0;
    p_interrupt_func = NULL;

    return stat;
}


//--------------------------------------------------------//
long ftimer_CurrentUsec(void)
{
    return 9999;
}


//---------------- Private Implementation -------------//

//--------------------------------------------------------//
void CALLBACK p_TimerCallback(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
    _counter++;



    /// <summary>Used for more accurate timing.</summary>
    // readonly Stopwatch _sw = new Stopwatch();

    // /// <summary>Indicates whether or not the timer is running.</summary>
    // bool _running = false;

    // /// <summary>Stopwatch support.</summary>
    // long _lastTicks = -1;

    // if(_running)
    // {
    //     if(_lastTicks != -1)
    //     {
    //         // When are we?
    //         long t = _sw.ElapsedTicks; // snap
    //         double msec = (t - _lastTicks) * 1000D / Stopwatch.Frequency;
    //         _lastTicks = t;

    //         // Check for expirations.
    //         timer.current += msec;
    //         if((timer.period - timer.current) < allowance)
    //         {
    //             elapsed.Add(tid);
    //             timer.current = 0.0;
    //             TimerElapsedEvent?.Invoke(this, new TimerEventArgs() { ElapsedTimers = elapsed });
    //         }
    //     }
    //     else
    //     {
    //         // Starting.
    //         _lastTicks = _sw.ElapsedTicks;
    //     }
    // }

}
