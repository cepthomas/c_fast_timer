# c_fast_timer

A fast (msec) timer based on system multimedia timer.
The win multimedia timer is erratic. Using a one msec tick (fastest), the measured interval is +-100 us.
Also note that it takes about 10 ticks to settle down after start.
This component attempts to reduce the error by running at one msec and managing the requested periods manually.
This is accomplished by using a stopwatch to actually measure the elapsed time rather than trust the mm timer period.
It seems to be an improvement.
