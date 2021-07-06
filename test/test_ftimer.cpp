#include <cstdio>
#include <cstring>

#include "pnut.h"

extern "C"
{
#include "ftimer.h"
}


// /// Type: Function pointer for handling of timer ticks.
// typedef void (*ftimer_InterruptFunc_t)(void);

// /// Initialize the module.
// /// @param[in] fp Callback function on period.
// /// @param[in] ft_res Resolution of fast timer.
// /// @return 0=ok 1=...
// int ftimer_Init(ftimer_InterruptFunc_t fp, unsigned ft_res);

// /// Enter the forever loop.
// /// @param[in] Desired period in msec, 0 stops.
// /// @return Status on exit.
// int ftimer_Run(unsigned period);

// /// Clean up module resources.
// /// @return 0=ok 1=...
// int ftimer_Destroy(void);

// /// Get number of microseconds since beginning.
// /// @return Microseconds.
// long ftimer_CurrentUsec(void);



/////////////////////////////////////////////////////////////////////////////
UT_SUITE(FTIMER_BASIC, "Test all ftimer functions.")
{
    // // Make a dict with string key. create_str_dict() tests dict_create() and dict_Set().
    // dict_t* mydict = create_str_dict();
    // UT_NOT_NULL(mydict);
    // UT_EQUAL(dict_Count(mydict), 184);

    // test_struct_t* ts = NULL;
    // test_struct_t* tsret = NULL;
    // key_t key;

    // // Good
    // key.ks = "SOMETHING";
    // UT_EQUAL(dict_Get(mydict, key, (void**)&ts), RS_PASS);
    // UT_NOT_NULL(ts);
    // UT_EQUAL(ts->anumber, 138);
    // UT_STR_EQUAL(ts->astring, "Ajay_138");

    // // Bad
    // key.ks = "AAAAAA";
    // UT_EQUAL(dict_Get(mydict, key, (void**)&ts), RS_FAIL);

    return 0;
}
