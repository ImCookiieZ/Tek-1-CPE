cmake_minimum_required(VERSION 3.15)
project(generator C)

set(CMAKE_C_STANDARD 99)

file (GLOB lib_dir
        "lib/my/*.c")

add_executable(generator ${lib_dir} src/do_additional_functions.c src/main.c
        src/error.c src/stacks.c src/df_alg.c )