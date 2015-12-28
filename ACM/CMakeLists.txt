cmake_minimum_required(VERSION 3.3)
project(ACM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Team.cpp Team.h Person.cpp Person.h List.h)
add_executable(ACM ${SOURCE_FILES})