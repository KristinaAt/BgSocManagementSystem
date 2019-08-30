cmake_minimum_required(VERSION 3.14)
project(BgSocManagementSystem C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(main_functions)

add_executable(BgSocManagementSystem
        main_functions/add_member.c
        main_functions/add_member.h
        main_functions/delete_record.c
        main_functions/delete_record.h
        main_functions/list_records.c
        main_functions/list_records.h
        main_functions/menu.c
        main_functions/menu.h
        main_functions/modify_record.c
        main_functions/modify_record.h
        helper_functions.c
        helper_functions.h
        main.c)
