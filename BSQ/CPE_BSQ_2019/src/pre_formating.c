/*
** EPITECH PROJECT, 2019
** f
** File description:
** s
*/

#include "../include/tmp.h"

char *skip_first(char *buffer, int len)
{
    int counter = 0;
    int j;
    int i = 0;
    char *new;
    int o;
    int nb = my_getnbr3(buffer);

    for (; buffer[i] != '\0' && buffer[i] != '\n'; i++);
    i++;
    new = malloc(sizeof(char) * (len - i + 1));
    for (j = 0, o = i; j < len - i; o++, j++) {
        if (buffer[o] == '\n')
            counter++;
        new[j] = buffer[o];
    }
    new[len - i] = '\0';
    if (counter == nb && i > 1)
        return (new);
    write(2, "Error: empty file or less lines\n", 32);
    return (NULL);
}

char **formating(char *new)
{
    char **array;
    int lines = 0;
    int columns = 0;

    for (int i = 0; new[i] != '\0'; i++)
        if (new[i] == '\n')
            lines++;
    if (lines == 0) {
        write(2, "Error: less lines\n", 19);
        return (NULL);
    }
    array = malloc(sizeof(char *) * (lines + 1));
    for (; new[columns] != '\n'; columns++);
    for (int i = 0; i < lines; i++)
        array[i] = malloc(sizeof(char) * (columns + 2));
    return (array);
}

int **get_int_map2(char **char_map, int **int_map, int columns)
{
    int i;
    int j;

    for (i = 0; char_map[i] != NULL; int_map[i + 1][columns + 1] = -1, i++) {
        int_map[i + 1] = malloc(sizeof(int) * (columns + 2));
        int_map[i + 1][0] = 0;
        for (j = 0; char_map[i][j] != '\n'; j += 1)
            if (char_map[i][j] == 'o')
                int_map[i + 1][j + 1] = 0;
            else if (char_map[i][j] == '.')
                int_map[i + 1][j + 1] = 1;
            else
                return (NULL);
        if (j != columns) {
            write(2, "different size\n", 15);
            return (NULL);
        }
    }
    int_map[i + 1] = NULL;
    return (int_map);
}

int **get_int_map(char **char_map, int size)
{
    int columns;
    int i;
    int j = 0;
    int c;
    int **int_map = malloc(sizeof(int *) * (size + 2));

    for (columns = 0; char_map[0][columns] != '\n'; columns++);
    int_map[0] = malloc(sizeof(int) * (columns + 2));
    for (c = 0; c <= columns; c++)
        int_map[0][c] = 0;
    int_map[0][c] = -1;
    int_map = get_int_map2(char_map, int_map, columns);
    return (int_map);
}