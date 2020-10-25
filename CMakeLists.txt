cmake_minimum_required(VERSION 3.17)
project(cpp_mod5)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -std=c++98")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fprofile-instr-generate -fcoverage-mapping")
endif ()

add_subdirectory(ex00)
add_subdirectory(ex01)
add_subdirectory(ex02)
add_subdirectory(ex03)