
#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <stdbool.h>


/// @brief Stopwatch similar to C# class.

//---------------- Public API ----------------------//

/// Initialize the module.
void stopwatch_Init(void);

/// Reset the start time.
void stopwatch_Reset(void);

/// How long since last stopwatch_Reset().
/// @return msec
double stopwatch_ElapsedMsec(void);

/// How long since stopwatch_Init().
/// @return msec
double stopwatch_TotalElapsedMsec(void);

#endif // STOPWATCH_H
