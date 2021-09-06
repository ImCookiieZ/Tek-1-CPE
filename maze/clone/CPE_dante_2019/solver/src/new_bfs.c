/*
** EPITECH PROJECT, 2020
** solver
** File description:
** new_bfs.c
*/

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
        if (map[i + 1])
            my_printf("%s\n", map[i]);
        else
            my_printf("%s", map[i]);
    }
    return (2);
}

int in_loop(map_t map, int **visited, coord_t *cur, head_t *stack)
{
    coord_t *new = NULL;

    if (cur->y > map.height - 1 || cur->x > map.width - 1 || cur->x < 0 ||
    cur->y < 0 || visited[cur->y][cur->x] == TRUE)
        return (1);
    if (map.map[cur->y][cur->x] == 'X') {
        visited[cur->y][cur->x] = TRUE;
        return (1);
    }
    if (cur->y == map.height - 1 && cur->x == map.width - 1)
        return (my_print_path(backtrack_path(cur), map.map));
    for (int i = 0; i < 4; i++) {
        new = malloc(sizeof(coord_t));
        new->x = col_g[i] + cur->x;
        new->y = row_g[i] + cur->y;
        new->prev = cur;
        my_push(new, stack);
        visited[cur->y][cur->x] = TRUE;
    }
    return (0);
}

int bfs_new(char **ar, int width, int height)
{
    int in_loop_ret = 0;
    map_t map = {ar, width, height};
    head_t *stack = prepare_stack();
    coord_t *start = prepare_co();
    int **visited = prepare_int_array(width, height);
    coord_t *cur = NULL;

    my_push(start, stack);
    while (stack->start) {
        cur = my_pop(stack);
        in_loop_ret = in_loop(map, visited, cur, stack);
        if (in_loop_ret == 1)
            continue;
        if (in_loop_ret == 2)
            return (1);
    }
    return (0);
}