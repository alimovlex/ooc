cmake_minimum_required(VERSION 3.14)
project(06 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(06
        main.c
        Circle.c
        Circle.h
        #circles.c
        Object.c
        Object.h
        Point.c
        Point.h)
        #points.c)
