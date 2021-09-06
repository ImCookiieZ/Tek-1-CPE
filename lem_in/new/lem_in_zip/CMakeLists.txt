cmake_minimum_required(VERSION 3.15)
project(lem_in C)

set(CMAKE_C_STANDARD 99)

file (GLOB lib_dir
        "lib/my/*.c")
file (GLOB prep_dir
        "preparation/*.c")

add_executable(lem_in ${lib_dir} ${prep_dir} src/alg.c src/len.c src/print_alg.c)