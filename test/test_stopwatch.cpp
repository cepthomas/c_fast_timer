#include <cstdio>
#include <cstring>

#include "pnut.h"

extern "C"
{
#include "stopwatch.h"
}


// /// Initialize the module.
// /// @return 0=ok 1=high res not available.
// int stopwatch_Init(void);

// /// Clean up module resources.
// /// @return 0=ok
// int stopwatch_Destroy(void);

// /// Start the stopwatch. This resets the start time.
// /// @return 0=ok 1=...
// int stopwatch_Start(void);

// /// Stop the stopwatch.
// /// @return 0=ok 1=...
// int stopwatch_Stop(void);

// /// Current status.
// /// @return T/F
// bool stopwatch_IsRunning(void);

// /// How long since Start().
// /// @return msec
// double stopwatch_ElapsedMilliseconds(void);

// /// How long since Start().
// /// @return ticks
// long stopwatch_ElapsedTicks(void);




/////////////////////////////////////////////////////////////////////////////
UT_SUITE(STOPWATCH_BASIC, "Test all stopwatch functions.")
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
