/*
** EPITECH PROJECT, 2020
** generator
** File description:
** perfect_dfs.c
*/

#include "../include/all_includes.h"

int row_g[5] = {-1, 0, 0, 1, 0};
int col_g[5] = {0, -1, 1, 0, 0};
int wall_x1[5] = {1, -1, 1, 1};
int wall_y1[5] = {-1, 1, 1, 1};
int wall_x2[5] = {-1, -1, 1, -1};
int wall_y2[5] = {-1, -1, -1, 1};

char **prepare_map(char **map, int height, int width)
{
    map = malloc(sizeof(char *) * (height + 1));
    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(char) * (width + 1));
        if (map[i] == NULL)
            my_error_exit("map[i] allocation failed\n");
        for (int j = 0; j < width; j++)
            map[i][j] = ' ';
        map[i][width] = 0;
    }
    map[height] = NULL;
    map[0][0] = '*';
    return (map);
}

int is_valid_wall(map_t maps, coord_t *el, int k)
{
    int row_wall1 = el->y + wall_y1[k];
    int col_wall1 = el->x + wall_x1[k];
    int row_wall2 = el->y + wall_y2[k];
    int col_wall2 = el->x + wall_x2[k];

    if ((row_wall1 >= 0 && row_wall1 < maps.height) && (col_wall1 >= 0 &&
    col_wall1 <= maps.width) && maps.map[row_wall1][col_wall1] == '*')
        return (0);
    if ((row_wall2 >= 0 && row_wall2 < maps.height) && (col_wall2 >= 0 &&
    col_wall2 <= maps.width) && maps.map[row_wall2][col_wall2] == '*')
        return (0);
    return (1);
}

int is_valid(map_t maps, coord_t *el, int k)
{
    int row_target = el->y + row_g[k] * 2;
    int col_target = el->x + col_g[k] * 2;
    int tmp_x = 0;
    int tmp_y = 0;

    if ((row_target < 0) || (row_target >= maps.height) || (col_target <
    0) || (col_target >= maps.width) || maps.map[row_target][col_target] == '*')
        return (0);
    for (int i = 0; i < 4; i++) {
        tmp_y = row_target + row_g[i];
        tmp_x = col_target + col_g[i];
        if ((tmp_y >= 0 && tmp_y < maps.height) && (tmp_x >= 0 && tmp_x <
        maps.width) && maps.map[tmp_y][tmp_x] == '*')
            return (0);
    }
    if (is_valid_wall(maps, el, k) == 0)
        return (0);
    return (1);
}

map_t my_change_map(map_t map, coord_t *el, int k)
{
    int row_target = el->y + row_g[k] * 2;
    int col_target = el->x + col_g[k] * 2;

    map.map[row_target][col_target] = '*';
    for (int i = 0; i < 4; i++) {
        if ((row_target + row_g[i] >= 0 &&
        row_target + row_g[i] < map.height) &&
        (col_target + col_g[i] >= 0 && col_target + col_g[i] < map.width)) {
            map.map[row_target + row_g[i]][col_target + col_g[i]] = 'X';
        }
    }
    map.map[el->y + row_g[k]][el->x + col_g[k]] = '*';
    if ((el->y + wall_y1[k] >= 0 && el->y + wall_y1[k] < map.height) &&
        el->x + wall_x1[k] >= 0 && el->x + wall_x1[k] < map.width)
        map.map[el->y + wall_y1[k]][el->x + wall_x1[k]] = 'X';
    if ((el->y + wall_y2[k] >= 0 && el->y + wall_y2[k] < map.height) &&
        el->x + wall_x2[k] >= 0 && el->x + wall_x2[k] < map.width)
        map.map[el->y + wall_y2[k]][el->x + wall_x2[k]] = 'X';
    return (map);
}

map_t make_imperfect(map_t map)
{
    int max = rand() % map.width;
    int r = 0;
    int c = 0;

    for (int y = 0; map.map[y] && c < max; y++) {
        for (int x = 0; map.map[y][x] && c < max; x++) {
            if (map.map[y][x] == 'X')
                r = rand() % 2;
            if (r == 1) {
                map.map[y][x] = '*';
                c++;
            }
        }
    }
    return (map);
}