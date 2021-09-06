cmake_minimum_required(VERSION 3.15)
project(solver C)

set(CMAKE_C_STANDARD 99)

file (GLOB lib_dir
        "lib/my/*.c")

add_executable(solver ${lib_dir} src/main.c src/error.c src/stacks.c
        src/new_bfs.c src/stacks.c)