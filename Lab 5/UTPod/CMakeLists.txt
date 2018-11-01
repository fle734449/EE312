cmake_minimum_required(VERSION 3.12)
project(UTPod)

set(CMAKE_CXX_STANDARD 14)

add_executable(UTPod UtPodDriver.cpp UtPod.h song.h UtPod.cpp song.cpp)