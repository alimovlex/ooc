cmake_minimum_required(VERSION 3.14)
project(01 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(01
        main.c
        new.h
        Object.h
        Set.c
        Set.h)
