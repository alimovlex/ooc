cmake_minimum_required(VERSION 3.13)  # Automatically generated syntax
project(sandbox)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(CMAKE_C_FLAGS "-DLOG_USE_COLOR")
include_directories(${PROJECT_SOURCE_DIR}/inc)
file(GLOB SRCS "${PROJECT_SOURCE_DIR}/src/*.c" "main.c")
add_executable(sample ${SRCS})
target_link_libraries(sample Threads::Threads)

