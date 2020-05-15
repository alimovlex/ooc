cmake_minimum_required(VERSION 3.14)
project(05 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(05
        binary.c
        binary.h
        mathlib.c
        mathlib.h
        Name.c
        Name.h
        main.c
        main.h
        value.c
        value.h
        Var.c
        Var.h)
target_link_libraries(05 m)