/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** add_all_includes
*/

#include "my.h"

#define TRUE 1
#define FALSE 2

typedef struct my_map_vars {
    char **map;
    int width;
    int height;
} map_t;

typedef struct my_coordinates {
    int x;
    int y;
    struct my_coordinates *prev;
    int len;
} coord_t;

typedef struct my_stack {
    coord_t *el_prev;
    int x;
    int y;
    int len;
    struct my_stack *next;
    struct my_stack *prev;
} stack_t;

typedef struct my_head {
    stack_t *start;
    stack_t *last;
} head_t;

head_t *prepare_stack();
coord_t *prepare_co();
void my_error_exit(char *error_msg);
coord_t *my_pop(head_t *stack);
void my_push(coord_t *coord, head_t *stack);
int bfs_new(char **map, int width, int height);
head_t *backtrack_path(coord_t *cur);
int **prepare_int_array(int width, int height);