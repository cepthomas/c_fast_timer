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
    int status = stopwatch_Init();
    UT_EQUAL(status, 0);

// int stopwatch_Destroy(void);
// int stopwatch_Start(void);
// int stopwatch_Stop(void);
// bool stopwatch_IsRunning(void);
// double stopwatch_ElapsedMilliseconds(void);
// long stopwatch_ElapsedTicks(void);

    return 0;
}
