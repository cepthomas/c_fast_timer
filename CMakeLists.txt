cmake_minimum_required(VERSION 3.5)

project(ftimer_test)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# needs -g to debug.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Werror -Wno-unused-variable")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")


include_directories(
    source
    ../c_bag_of_tricks/source
    ../c_bag_of_tricks/pnut
    )

# Source files.
add_executable(ftimer_test
    source/private/ftimer.c
    source/private/stopwatch.c
    test/main.cpp
    test/test_ftimer.cpp
    test/test_stopwatch.cpp
    ../c_bag_of_tricks/pnut/pnut.cpp
    )

target_link_libraries(ftimer_test libwinmm.a)
