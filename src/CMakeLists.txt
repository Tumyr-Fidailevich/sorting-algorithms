cmake_minimum_required(VERSION 3.25)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(sorting_algorithms main.cpp ${MY_INCLUDE_DIR}/quicksort.h ${MY_INCLUDE_DIR}/mergesort.h)
target_include_directories(sorting_algorithms PUBLIC ${MY_INCLUDE_DIR})