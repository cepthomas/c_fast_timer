# Build the module with its unit tests.
# This is a Windows 64 bit build. PATH must include ...\mingw64\bin.

cmake_minimum_required(VERSION 3.5)
project(ftimer_test)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

set(CBOT "C:/Dev/repos/C/c_bag_of_tricks")

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

target_link_libraries(ftimer_test
    libwinmm.a
    )
