/*
** EPITECH PROJECT, 2019
** algorythm
** File description:
** for bsq
*/

#include "../include/my.h"
#include "../include/tmp.h"

int get_min(int tl, int tr, int l)
{
    int *array = malloc(sizeof(int) * 3);
    int res = 0;

    array[0] = tl;
    array[1] = tr;
    array[2] = l;
    array = my_sort_int_array(array, 3);
    res = array[0] + 1;
    free(array);
    return (res);
}

int **bsq_alg(int **array)
{
    int line = 1;
    int column = 1;

    for (; array[line] != NULL; line++) {
        for (column = 1; array[line][column] != -1; column++) {
            if (array[line][column] == 1)
                array[line][column] = get_min(array[line - 1][column - 1]\
, array[line - 1][column], array[line][column - 1]);
        }
    }
    return (array);
}

int *biggest_nb(int **array)
{
    int *square = malloc(sizeof(int) * (4));

    square[0] = 0;
    square[1] = 0;
    square[2] = 0;
    for (int a = 0; array[a] != NULL; a++)
        for (int i = 0; array[a][i] != -1; i++)
            if (square[0] < array[a][i]) {
                square[0] = array[a][i];
                square[1] = a;
                square[2] = i;
            }
    return (square);
}

char **modify_array(char **char_map, int size)
{
    int *square;
    int **int_map = get_int_map(char_map, size);

    int_map = bsq_alg(int_map);
    square = biggest_nb(int_map);
    char_map = put_x(char_map, square);
    for (int i = 0; int_map[i] != NULL; i++)
        free(int_map[i]);
    my_putting(char_map);
    free(int_map);
    free(square);
    return (char_map);
}

char **put_x(char **map, int *square)
{
    for (int i = square[0]; i > 0; i--)
        for (int j = square[0]; j > 0; j--)
            map[square[1] - i][square[2] - j] = 'x';
    return (map);
}