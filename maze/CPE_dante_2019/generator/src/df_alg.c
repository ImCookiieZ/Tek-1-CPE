/*
** EPITECH PROJECT, 2020
** generator
** File description:
** algoryth.c
*/

#include "../include/all_includes.h"

int check_valid_directions(coord_t *co, head_t *stack, map_t map)
{
    int ret = 0;
    int d = 0;
    int *directions = malloc(sizeof(int) * 4);

    if (directions == NULL)
        my_error_exit("direction allocation failed\n");
    for (int k = 0; k < 4; k++) {
        if (is_valid(map, co, k) == 1) {
            directions[d] = k;
            d++;
        }
    }
    if (d == 0) {
        free(directions);
        free(co);
        return (42);
    }
    ret = directions[rand() % d];
    free(directions);
    return (ret);
}

map_t make_valgrind_clean(map_t map, head_t *stack, coord_t *co)
{
    while (stack->start) {
        co = my_pop(stack);
        free(co);
    }
    for (int i = 0; map.map[i]; i++)
        if (map.map[i][map.width - 1] == ' ')
            map.map[i][map.width - 1] = 'X';
    for (int i = 0; map.map[map.height - 1][i]; i++)
        if (map.map[map.height - 1][i] == ' ')
            map.map[map.height - 1][i] = 'X';
    map.map[map.height - 1][map.width - 1] = '*';
    if (map.height > 1 && map.map[map.height - 2][map.width - 1] == 'X' &&
    map.map[map.height - 1][map.width - 2] == 'X') {
        if (rand() % 2)
            map.map[map.height - 2][map.width - 1] = '*';
        else
            map.map[map.height - 1][map.width - 2] = '*';
    }
    return (map);
}

map_t do_loop(coord_t *co, head_t *stack, map_t map)
{
    int random = 0;
    coord_t *new = NULL;

    co = my_pop(stack);
    random = check_valid_directions(co, stack, map);
    if (random == 42)
        return map;
    map = my_change_map(map, co, random);
    new = malloc(sizeof(coord_t));
    if (new == NULL)
        my_error_exit("allocation of value new in line 197 faild");
    new->prev = co;
    new->x = co->x + col_g[random] * 2;
    new->y = co->y + row_g[random] * 2;
    my_push(co, stack);
    my_push(new, stack);
    free(co);
    free(new);
    return (map);
}

map_t control_map(map_t map)
{
    for (int i = 0; map.map[i]; i++) {
        for (int j = 0; map.map[j]; j++)
            if (map.map[i][j] == ' ')
                map.map[i][j] = 'X';
    }
    for (int i = 0; i < map.height; i++) {
        for (int j = 0; j < map.width; j++) {
            switch (map.map[i][j]) {
                case 'X': my_putstr("\033[31m");
                    break;
                case '*': my_putstr("\033[32m");
                    break;
                case 'o': my_putstr("\033[33m");
                    break;
            }
            my_putchar(map.map[i][j]);
            my_putstr("\033[0m");
        }
        if (i != map.height) my_putchar('\n');
    }
    return map;
}

void do_perfect_dfa(int width, int height, int perfect)
{
    head_t *stack = create_stack();
    coord_t *co = create_co();
    map_t map = {NULL, width, height, perfect};

    map.map = prepare_map(map.map, height, width);
    my_push(co, stack);
    free(co);
    while (stack->start)
        map = do_loop(co, stack, map);
    map = make_valgrind_clean(map, stack, co);
    if (map.perfect == 0)
        map = make_imperfect(map);
    free(stack);
    map = control_map(map);
    for (int i = 0; i < map.height; i++) free(map.map[i]);
    free(map.map);
}