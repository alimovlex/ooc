cmake_minimum_required(VERSION 3.14)
project(04 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(04
        Circle.c
        Circle.h
        main.c
        new.c
        new.h
        Point.c
        Point.h)
