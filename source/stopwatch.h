
#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <stdbool.h>


/// @brief Stopwatch similar to C# class.

//---------------- Public API ----------------------//

/// Initialize the module.
/// @return 0=ok 1=high res not available.
int stopwatch_Init(void);

/// Reset the start time.
/// @return 0=ok 1=invalid stopwatch
int stopwatch_Reset(void);

/// How long since stopwatch_Reset().
/// @return msec
double stopwatch_ElapsedMsec(void);

#endif // STOPWATCH_H
