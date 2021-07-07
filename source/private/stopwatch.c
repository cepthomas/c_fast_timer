
#include <windows.h>
#include <stdio.h>
#include "stopwatch.h"


//---------------- Private Declarations ------------------//

/// Dawn of time.
static long long p_start_tick;

/// False if high res is not available.
static bool p_valid = false;

/// The current performance counter scale, in ticks per microsecond.
static double p_ticks_per_msec;

/// The current performance counter value.
/// @return ticks
static long long p_CurrentTick(void);


//---------------- Public API Implementation -------------//

//--------------------------------------------------------//
int stopwatch_Init(void)
{
    p_start_tick = 0;

    LARGE_INTEGER f;
    if(QueryPerformanceFrequency(&f))
    {
        p_valid = true;
        p_ticks_per_msec = (double)f.QuadPart / 1000.0;
        stopwatch_Reset();
    }
    else
    {
        p_valid = false;
    }

    return p_valid ? 0 : 1;
}

//--------------------------------------------------------//
int stopwatch_Reset(void)
{
    if(p_valid)
    {
        p_start_tick = p_CurrentTick();
    }

    return p_valid ? 0 : 1;
}

//--------------------------------------------------------//
double stopwatch_ElapsedMsec(void)
{
    long long elapsed_ticks = p_CurrentTick() - p_start_tick;

    if(elapsed_ticks < 0)
    {
        // When measuring small time periods the StopWatch.Elapsed* properties can return negative values.
        // This is due to bugs in the basic input/output system (BIOS) or the hardware
        // abstraction layer (HAL) on machines with variable-speed CPUs (e.g. Intel SpeedStep).
        elapsed_ticks = 0;
    }

    double msec = (double)elapsed_ticks / p_ticks_per_msec;
    return msec;
}

//---------------- Private Implementation -------------//

//--------------------------------------------------------//
long long p_CurrentTick(void)
{
    LARGE_INTEGER ts;
    QueryPerformanceCounter(&ts);
    return ts.QuadPart;
}
