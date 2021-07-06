
#ifndef STOPWATCH_H
#define STOPWATCH_H


#include <stdbool.h>


/// @brief Stopwatch similar to C# class.

//---------------- Public API ----------------------//

/// Initialize the module.
/// @return 0=ok 1=high res not available.
int stopwatch_Init(void);

/// Clean up module resources.
/// @return 0=ok
int stopwatch_Destroy(void);

/// Start the stopwatch. This resets the start time.
/// @return 0=ok 1=...
int stopwatch_Start(void);

/// Stop the stopwatch.
/// @return 0=ok 1=...
int stopwatch_Stop(void);

/// Current status.
/// @return T/F
bool stopwatch_IsRunning(void);

/// How long since Start().
/// @return msec
double stopwatch_ElapsedMilliseconds(void);

/// How long since Start().
/// @return ticks
long stopwatch_ElapsedTicks(void);

#endif // STOPWATCH_H
