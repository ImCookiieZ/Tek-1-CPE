cmake_minimum_required(VERSION 3.15)
project(CPE_getnextline_2019 C)

set(CMAKE_C_STANDARD 99)

add_executable(CPE_getnextline_2019 src/main.c lib/my/my_putchar.c
        lib/my/my_putstr.c lib/my/my_strlen.c main.c)