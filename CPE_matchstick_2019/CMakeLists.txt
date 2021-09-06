cmake_minimum_required(VERSION 3.15)
project(CPE_matchstick_2019 C)

set(CMAKE_C_STANDARD 99)
file (GLOB lib_dir
        "lib/my/*.c")
add_executable(CPE_matchstick_2019 ${lib_dir} src/main.c src/get_inputs.c src/game_loop.c src/preparation.c src/ai.c src/new_class.c src/final.c)