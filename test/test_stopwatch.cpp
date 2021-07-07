
//#include <Windows.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>

#include "pnut.h"

extern "C"
{
#include "stopwatch.h"
}



/////////////////////////////////////////////////////////////////////////////
UT_SUITE(STOPWATCH_BASIC, "Test all stopwatch functions.")
{
    // Happy path.
    UT_EQUAL(stopwatch_Init(), 0);
    UT_CLOSE(stopwatch_ElapsedMsec(), 0.0, 0.01);

    UT_EQUAL(stopwatch_Reset(), 0);
    UT_CLOSE(stopwatch_ElapsedMsec(), 0.0, 0.01);

    sleep(1);

    UT_CLOSE(stopwatch_ElapsedMsec(), 1000.0, 5.0); // because sleep() is sloppy

    return 0;
}
