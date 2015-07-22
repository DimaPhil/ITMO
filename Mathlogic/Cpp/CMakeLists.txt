cmake_minimum_required(VERSION 3.2)
project(CLionProjects)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall -O2 -Werror")

set(SOURCE_FILES Expressions.cpp Parser.cpp Utils.cpp)
set(HEADER_FILES Expressions.h Parser.h Utils.h)
set(MAIN_FILES main.cpp HW1.cpp HW2.cpp HW3.cpp)
add_executable(CLionProjects ${HEADER_FILES} ${SOURCE_FILES} ${MAIN_FILES})