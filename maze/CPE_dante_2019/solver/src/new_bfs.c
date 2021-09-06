/*
** EPITECH PROJECT, 2020
** solver
** File description:
** new_bfs.c
*/

#include <zconf.h>
#include "../include/all_includes.h"

int col_g[5] = {1, 0, -1, 0, 0};
int row_g[5] = {0, 1, 0, -1, 0};

int my_print_path(head_t *stack, char **map)
{
    coord_t *cell = my_pop(stack);
    while (cell) {
        map[cell->y][cell->x] = 'o';
        cell = cell->prev;
    }
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[j]; j++) {
            switch (map[i][j]) {
                case 'X': my_putstr("\033[1;31m");
                    break;
                case '*': my_putstr("\033[1;32m");
                    break;
                case 'o': my_putstr("\033[01;33m");
                    break;
            }
            my_putchar(map[i][j]);
            my_putstr("\033[0m");
        }
        if (map[i + 1]) my_putchar('\n');
    }
    return (2);
}

map_t do_in_loop(map_t map, int **visited, coord_t *cur, head_t *stack)
{
    coord_t *new = NULL;
    if (cur->y > map.height - 1 || cur->x > map.width - 1 || cur->x < 0 ||
    cur->y < 0 || visited[cur->y][cur->x] == TRUE) {
        map.ret = 1;
        return (map);
    }
    if (map.map[cur->y][cur->x] == 'X') {
        visited[cur->y][cur->x] = TRUE;
        map.ret = 1;
        return (map);
    }
    if (cur->len >= map.fin) {
        return (map);
    }
    if (cur->y == map.height - 1 && cur->x == map.width - 1) {
        my_pop(map.fin_stack);
        my_push(cur, map.fin_stack);
        map.fin = cur->len;
        map.ret = 1;
        return (map);
    }
    for (int i = 0; i < 4; i++) {
        new = malloc(sizeof(coord_t));
        if (new == NULL) my_error_exit("malloc of new pos failed\n");
        new->x = col_g[i] + cur->x;
        new->y = row_g[i] + cur->y;
        new->prev = cur;
        new->len = cur->len;
        my_push(new, stack);
        visited[cur->y][cur->x] = TRUE;
    }
    map.ret = 0;
    return (map);
}
/*
int my_loop2(map_t map, int **visited, head_t *stack)
{
    int ret = 0;
    coord_t *cur = NULL;

    if (!(stack->start))
        return ret;
    cur = my_pop(stack);
    ret = do_in_loop(map, visited, cur, stack);
    if (ret == 2)
        return (1);
    else
        return (my_loop2(map, visited, stack));
}
*/
int do_bfs_new(char **ar, int width, int height)
{
    //  int in_loop_ret = 0;
    map_t map = {ar, width, height, INT_MAX, 0, malloc(sizeof(head_t))};
    head_t *stack = prepare_stack();
    coord_t *start = prepare_co();
    int **visited = prepare_int_array(width, height);
    coord_t *cur = NULL;

    map.fin_stack->start = NULL;
    map.fin_stack->last = NULL;
    my_push(start, stack);
    my_push(start, map.fin_stack);
    while (stack->start) {
        cur = my_pop(stack);
        map = do_in_loop(map, visited, cur, stack);
    }
    cur = my_pop(map.fin_stack);
    if (map.fin != INT_MAX) {
        my_print_path(backtrack_path(cur), map.map);
        return (1);
    }
    else
        return (0);
}