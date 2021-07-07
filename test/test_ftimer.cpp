
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <unistd.h>

#include "pnut.h"

extern "C"
{
#include "ftimer.h"
#include "stopwatch.h"
}


static double p_start_msec = 0.0;
#define TEST_COUNT 20
double p_test_res[TEST_COUNT];
int p_test_index = 0;

void PeriodicInterruptFunc(double msec)
{
    if(p_test_index < TEST_COUNT)
    {
        p_test_res[p_test_index] = msec;
        p_test_index++;
    }
    else
    {
        // Stop.
        ftimer_Run(0);
    }
}

/////////////////////////////////////////////////////////////////////////////
UT_SUITE(FTIMER_BASIC, "Test all ftimer functions.")
{
    // Happy path.
    unsigned res = 5;
    UT_EQUAL(ftimer_Init(PeriodicInterruptFunc, res), 0);

    // Grab the stopwatch time.
    p_start_msec = stopwatch_ElapsedMsec();

    // Go.
    UT_EQUAL(ftimer_Run(17), 0);

    int timeout = 3;
    while(ftimer_IsRunning())// && timeout > 0)
    {
        sleep(1);
        timeout--;
    }

    ftimer_Destroy();

    //TODO check p_test_res[]

    return 0;
}

