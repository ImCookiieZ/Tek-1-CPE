/*
** EPITECH PROJECT, 2020
** generator
** File description:
** depth_first_array.c
*/

#include "../include/all_includes.h"
/*
void my_push(int x, int y, head_t *stack)
{
    stack_t *el = malloc(sizeof(stack_t));

    if (el == NULL)
        my_error_exit("push failed because of malloc\n");
    el->x = x;
    el->y = y;
    el->prev = stack->last;
    el->next = NULL;
    if (stack->start == NULL)
        stack->start = el;
    else
        stack->last->next = el;
    stack->last = el;
}

coord_t my_pop(head_t *stack)
{
    coord_t ret = {stack->last->x, stack->last->y};
    stack_t *tmp = stack->last;

    stack->last = stack->last->prev;
    if (stack->last == NULL)
        stack->start = NULL;
    free(tmp);
    return (ret);
}

char *get_max_directions(char **map, coord_t cell)
{
    char *directions = malloc(sizeof(char) * 5);
    int counter = 0;

    if (directions == NULL)
        my_error_exit("directions - malloc failed\n");
    if (map[cell.y + 1] && map[cell.y + 1][cell.x] == '-') {
        directions[counter] = 'D';
        counter++;
    }
    if (cell.y > 0 && map[cell.y - 1][cell.x] == '-') {
        directions[counter] = 'T';
        counter++;
    }
    if (map[cell.y][cell.x + 1] == '-') {
        directions[counter] = 'R';
        counter++;
    }
    if (cell.x > 0 && map[cell.y][cell.x - 1] == '-') {
        directions[counter] = 'L';
        counter++;
    }
    directions[counter] = '\0';
    return (directions);
}

coord_t change_map(char direction, char **map, coord_t cell, head_t *stack)
{
    switch (direction) {
        case 'T':
            map[--cell.y][cell.x] = '*';
            break;
        case 'D':
            map[++cell.y][cell.x] = '*';
            break;
        case 'L':
            map[cell.y][--cell.x] = '*';
            break;
        case 'R':
            map[cell.y][++cell.x] = '*';
            break;
        default:
            my_error_exit("impossible direction\n");
    }
    my_push(cell.x, cell.y, stack);
    return cell;
}

char *map_wall(char *directions, char **map, coord_t cell, int my_rand)
{
    int len = my_strlen(directions) - 1;

    for (int i = my_rand; i < len; i++)
        directions[i] = directions[i + 1];
    if (len > 0) {
        my_rand = rand() % len;
        switch (directions[my_rand]) {
            case 'T':
                map[--cell.y][cell.x] = 'x';
                break;
            case 'D':
                map[++cell.y][cell.x] = 'x';
                break;
            case 'L':
                map[cell.y][--cell.x] = 'x';
                break;
            case 'R':
                map[cell.y][++cell.x] = 'x';
                break;
            default:
                my_error_exit("impossible direction\n");
        }

    }
    return (directions);
}

void my_backtracker(char **map, head_t *stack)
{
    coord_t cell;
    char *directions = NULL;
    int my_rand = 0;
    int len = 0;

    if (stack->start) {
        cell = my_pop(stack);
        if (cell.x == stack->x && cell.y == stack->y)
            return;
        map[cell.y][cell.x] = '*';
        directions = get_max_directions(map, cell);
        if ((len = my_strlen(directions)) == 0) {
            free(directions);
            my_backtracker(map, stack);
            return;
        }
        my_push(cell.x, cell.y, stack);
        my_rand = rand() % len;
        cell = change_map(directions[my_rand], map, cell, stack);
        directions = map_wall(directions, map, cell, my_rand);
        free(directions);
        my_backtracker(map, stack);
    }
}


char *depth_first_alg(int width, int height)
{
    char **map = malloc(sizeof(char *) * (height + 1));
    head_t *stack = malloc(sizeof(head_t));

    srand(time(NULL));
    if (map == NULL || stack == NULL) my_error_exit("map or stack failed\n");
    stack->start = NULL;
    stack->last = NULL;
    stack->x = width - 1;
    stack->y = height - 1;
    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(char) * (width + 1));
        for (int j = 0; j < width; j++)
            map[i][j] = '-';
        map[i][width] = '\0';
    }
    map[height] = NULL;
    my_push(0, 0, stack);
    my_backtracker(map, stack);
    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j]; j++)
            if (map[i][j] == '-')
                map[i][j] = 'x';
    if (map[height - 1][width - 1] == 'x') {
        while (stack->start)
            my_pop(stack);
        depth_first_alg(width, height);
    }
    else
        for (int i = 0; map[i]; i++)
            map[i + 1] ? my_printf("%s\n", map[i]) : my_printf("%s", map[i]);
    for (int i = 0; map[i]; i++)
        free(map[i]);
    while (stack->start)
        my_pop(stack);
    free(map);
    free(stack);
    return (NULL);
}/*