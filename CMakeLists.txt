cmake_minimum_required(VERSION 3.14)
project(BgSocManagementSystem C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(BgSocManagementSystem
        main.c
        system_functions.c
        system_functions.h)
