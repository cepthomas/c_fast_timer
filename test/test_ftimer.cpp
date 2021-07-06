#include <cstdio>
#include <cstring>

#include "pnut.h"

extern "C"
{
#include "ftimer.h"
}



void PeriodicInterruptFunc(void)
{

}

/////////////////////////////////////////////////////////////////////////////
UT_SUITE(FTIMER_BASIC, "Test all ftimer functions.")
{
    // Happy path.
    unsigned res = 5;
    int status = ftimer_Init(PeriodicInterruptFunc, res);
    UT_EQUAL(status, 0);

// int ftimer_Init(ftimer_InterruptFunc_t fp, unsigned ft_res);
// int ftimer_Run(unsigned period);
// int ftimer_Destroy(void);
// long ftimer_CurrentUsec(void);

    return 0;
}

