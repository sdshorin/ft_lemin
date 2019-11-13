cmake_minimum_required(VERSION 3.14)
project(lem-in)

set(CMAKE_C_STANDARD 99)

set(SOURCES main.c)

include_directories(libft)
include_directories(includes)
add_executable(lem-in main.c src/read_input.c includes/lemin.h src/create_rooms.c src/store_input_strings.c src/get_links.c src/get_ants.c src/data_struct.c)
add_subdirectory(libft)
target_link_libraries(lem-in libft)
