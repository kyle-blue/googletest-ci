cmake_minimum_required(VERSION 3.00)
project(random_program)

set(CMAKE_CXX_STANDARD 17)

add_executable(random_program main.cpp Interpreter.cpp)