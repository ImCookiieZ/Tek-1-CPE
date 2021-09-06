cmake_minimum_required(VERSION 3.15)
project(CPE_pushswap_2019 C)

set(CMAKE_C_STANDARD 99)

add_executable(CPE_pushswap_2019 lib/my/my_getnbr.c lib/my/my_put_nbr.c
        lib/my/my_putchar.c lib/my/my_putstr.c src/preparation.c
    src/run_function.c src/swap.c src/rotate.c src/backrotation.c src/sort.c
        do_not_add_this.c src/my_merge.c)