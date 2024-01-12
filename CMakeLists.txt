cmake_minimum_required(VERSION 3.5)

project(ftimer_test)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# needs -g to debug.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

# TODO1 fix these paths. Or use built libs?
set(CBOT   "C:/Dev/repos/C/c_bag_of_tricks")

include_directories(
    source
    ${CBOT}/pnut
    )

# Source files.
add_executable(ftimer_test
    source/private/ftimer.c
    source/private/stopwatch.c
    test/main.cpp
    test/test_ftimer.cpp
    test/test_stopwatch.cpp
    ${CBOT}/pnut/pnut.cpp
    )

target_link_libraries(ftimer_test libwinmm.a)
