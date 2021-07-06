
#ifndef FTIMER_H
#define FTIMER_H


/// @brief A fast (msec) timer based on system multimedia timer.
/// The win multimedia timer is erratic. Using a one msec tick (fastest), the measured interval is +-100 us.
/// Also note that it takes about 10 ticks to settle down after start.
/// This component attempts to reduce the error by running at one msec and managing the requested periods manually.
/// This is accomplished by using a Stopwatch to actually measure the elapsed time rather than trust the mm timer period.
/// It seems to be an improvement.

//---------------- Public API ----------------------//

/// Type: Function pointer for handling of timer ticks.
typedef void (*ftimer_InterruptFunc_t)(void);

/// Initialize the module.
/// @param[in] fp Callback function on period.
/// @param[in] ft_res Resolution of fast timer.
/// @return 0=ok 1=...
int ftimer_Init(ftimer_InterruptFunc_t fp, unsigned ft_res);

/// Enter the forever loop.
/// @param[in] Desired period in msec, 0 stops.
/// @return Status on exit.
int ftimer_Run(unsigned period);

/// Clean up module resources.
/// @return 0=ok 1=...
int ftimer_Destroy(void);

/// Get number of microseconds since beginning.
/// @return Microseconds.
long ftimer_CurrentUsec(void);

#endif // FTIMER_H
