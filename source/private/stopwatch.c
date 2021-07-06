
#include <windows.h>
#include "stopwatch.h"


//---------------- Private Declarations ------------------//

/// Dawn of time.
static long p_start_time;

/// How long since start. TODO why carry this and not just calc everytime?
static long p_elapsed_time;

/// Current run status.
static bool p_running = false;

/// False if high res is not available.
static bool p_valid = false;

/// The current performance counter frequency, in ticks per second.
static long p_tick_frequency;

/// The current performance counter value, in ticks.
/// @return ticks
static long p_CurrentTick(void);

/// Ticks since stopwatch last started.
/// @return ticks
static long p_ElapsedTicks(void);


//---------------- Public API Implementation -------------//

//--------------------------------------------------------//
int stopwatch_Init(void)
{
    int status = 0;

    p_elapsed_time = 0;
    p_running = false;
    p_start_time = 0;

    LARGE_INTEGER f;
    if(QueryPerformanceFrequency(&f))
    {
        p_valid = true;
        p_tick_frequency = f.QuadPart;
    }
    else
    {
        p_valid = false;
        status = 1;
    }

    return status;
}

//--------------------------------------------------------//
int stopwatch_Destroy(void)
{
    // Nothing to do.
    return 0;
}

//--------------------------------------------------------//
int stopwatch_Start(void)
{
    int status = 0;

    if(!p_valid)
    {
        status = 1;
    }
    else // if(!p_running)
    {
        p_start_time = p_CurrentTick();
        p_running = true;
    }

    return status;
}

//--------------------------------------------------------//
int stopwatch_Stop(void)
{
    int status = 0;

    if(!p_valid)
    {
        status = 1;
    }
    else if(p_running)
    {
        // Stragglers?
        long elapsed = p_CurrentTick() - p_start_time;
        p_elapsed_time += elapsed;
        p_running = false;

        if(p_elapsed_time < 0)
        {
            // When measuring small time periods the StopWatch.Elapsed* properties can return negative values.
            // This is due to bugs in the basic input/output system (BIOS) or the hardware
            // abstraction layer (HAL) on machines with variable-speed CPUs (e.g. Intel SpeedStep).
            p_elapsed_time = 0;
        }
    }

    return status;
}

//--------------------------------------------------------//
bool stopwatch_IsRunning(void)
{
    return p_valid && p_running;
}

//--------------------------------------------------------//
double stopwatch_ElapsedMilliseconds(void)
{
    double msec = p_ElapsedTicks() * 1000.0 / p_tick_frequency;
    return msec;
}

//--------------------------------------------------------//
long stopwatch_ElapsedTicks(void)
{
    return p_ElapsedTicks();
}

//---------------- Private Implementation -------------//

//--------------------------------------------------------//
long p_ElapsedTicks(void)
{
    long time_elapsed = p_elapsed_time;

    if( p_running)
    {
        long elapsed_until_now = p_CurrentTick() - p_start_time;
        time_elapsed += elapsed_until_now;
    }
    return time_elapsed;
}

//--------------------------------------------------------//
long p_CurrentTick(void)
{
    LARGE_INTEGER ts;
    QueryPerformanceCounter(&ts);
    return ts.QuadPart;
}
