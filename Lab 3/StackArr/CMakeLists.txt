cmake_minimum_required(VERSION 3.12)
project(Stack C)

set(CMAKE_C_STANDARD 99)

add_executable(Stack driver.c stack312_arr.h stack312_arr.c)