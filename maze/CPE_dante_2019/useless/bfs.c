/*
** EPITECH PROJECT, 2020
** solver
** File description:
** bfs.c
*/

#include "../include/all_includes.h"
/*
int **prepare_int_array(int **visited, int width, int height)
{
    for (int h = 0; h < height; h++) {
        visited[h] = malloc(sizeof(int) * (width + 1));
        if (visited[h] == NULL)
            my_error_exit("one thing in 2d array - malloc failed\n");
        for (int k = 0; k < width; k++)
            visited[h][k] = FALSE;
        visited[h][width] = 2;
    }
    return (visited);
}
void bfs(char **map, int widht, int height)
{
    head_t *stack = malloc(sizeof(head_t));
    head_t *way = malloc(sizeof(head_t));
    map_t maps = {map, widht - 1, height - 1};
    coord_t coord = {0, 0, 0};
    int len = 0;
    int **visited = malloc(sizeof(int) * (height + 1));

    visited = prepare_int_array(visited, widht, height);
    stack->start = NULL;
    stack->last = NULL;
    way->start = NULL;
    way->last = NULL;
    if (map[0][0] == 'x') {
        my_putstr("no solution found\n");
        exit(0);
    }
    my_push(coord, 4, stack, 0);
    my_push(coord, 4, way, 0);



    //loop begins



    for (int counter = 0; stack->start; counter = 0) {
        coord = my_pop(stack);
        visited[coord.y][coord.x] = TRUE;
        len++;
        my_push(coord, 4, way, len);
        if (coord.x == widht - 1 && coord.y == height - 1)
            continue;
        for (int k = 0; k < 4; k++) {
            if (isValid(maps, coord, k, visited)) {
                my_push(coord, k, stack, 0);
                counter++;
            }
        }
        my_printf("x: %i y:%i - %i counter\n", coord.x, coord.y, counter);
        if (counter == 0) {
            len = my_pop(way).len;
            visited[coord.y][coord.x] = FALSE;
        }
    }
    my_printf("len: %i", len);
}*/