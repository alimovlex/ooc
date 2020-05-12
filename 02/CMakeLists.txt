cmake_minimum_required(VERSION 3.14)
project(02 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(02
        
        new.c
        new.h
        String.c
        String.h
        main.c)
