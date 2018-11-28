cmake_minimum_required(VERSION 3.12)
project(Linked C)

set(CMAKE_C_STANDARD 99)

add_executable(Linked driver.c stack312_ll.h stack312_ll.c)