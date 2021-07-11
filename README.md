# c_fast_timer

A fast (msec) timer based on Windows multimedia timer. The win multimedia timer is erratic with possible
errors of many msec.

This component attempts to reduce the error by running at one msec and managing the requested periods manually.
This is accomplished by using a stopwatch (modelled after the C# class) to actually measure the elapsed time
rather than trust the mm timer period. It seems to be an improvement with roughly +-1 msec precision on an
unloaded system. That should be good enough for midi.

See `test_ftimer.cpp` for usage.

# Build
A VS Code workspace using mingw and CMake is supplied.

This requires [c_bag_of_tricks](https://github.com/cepthomas/c_bag_of_tricks)
at the same level as this project. Maybe I'll make it a submodule some time.


# Reading
[Beware of QueryPerformanceCounter()](https://www.virtualdub.org/blog2/entry_106.html)
