cmake_minimum_required(VERSION 3.14)
project(lem-in)

set(CMAKE_C_STANDARD 99)

set(SOURCES main.c)

include_directories(libft)
include_directories(includes)
add_executable(lem-in main.c src/read_input.c includes/lemin.h)
add_subdirectory(libft)
target_link_libraries(lem-in libft)
