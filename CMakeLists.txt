cmake_minimum_required(VERSION 3.14)
project(lem-in)

set(CMAKE_C_STANDARD 99)

set(SOURCES src/main.c)
set(CMAKE_CXX_FLAGS g)
include_directories(libft)
include_directories(includes)
add_executable(lem-in src/main.c src/get_data.c includes/lemin.h src/get_rooms.c src/store_input_strings.c src/get_links.c src/get_ants.c src/init_data.c src/destroyers.c src/debug_info.c)
add_subdirectory(libft)
target_link_libraries(lem-in libft)
