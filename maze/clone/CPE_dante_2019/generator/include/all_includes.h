/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** add_all_includes
*/

#include "my.h"
#include <time.h>

#define TRUE 1
#define FALSE 0

extern int row_g[5];
extern int col_g[5];
extern int wall_x1[5];
extern int wall_y1[5];
extern int wall_x2[5];
extern int wall_y2[5];

typedef struct my_map_vars {
    char **map;
    int width;
    int height;
    int perfect;
} map_t;

typedef struct my_coordinates {
    int x;
    int y;
    struct my_coordinates *prev;
    int len;
} coord_t;

typedef struct my_stack {
    int x;
    int y;
    struct my_stack *next;
    struct my_stack *prev;
} stack_t;

typedef struct my_head {
    stack_t *start;
    stack_t *last;
} head_t;

//algorithm.c
void perfect_dfa(int width, int height, int perfect);

//do_additional_functions.c
char **prepare_map(char **map, int height, int width);
int isValid(map_t maps, coord_t *el, int k);
map_t my_change_map(map_t map, coord_t *el, int k);
map_t make_imperfect(map_t map);

//stacks.c
void my_push(coord_t *coord, head_t *stack);
coord_t *my_pop(head_t *stack);

//error.c
void my_put_error_str(char *str);
void my_error_exit(char *error_msg);

head_t *create_stack(void);
coord_t *create_co(void);