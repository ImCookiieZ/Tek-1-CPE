/*
** EPITECH PROJECT, 2019
** f
** File description:
** s
*/

#include "../include/my.h"
#include "../include/tmp.h"

char *skip_first(char *buffer, int len)
{
    int j;
    int i = 0;
    char *new;
    int o;

    for (; buffer[i] != '\0' && buffer[i] != '\n'; i++);
    i++;
    if (i == 1) {
        write(2, "Error: empy file\n", 17);
        return (NULL);
    }
    new = malloc(sizeof(char) * (len - i + 1));
    for (j = 0, o = i; j < len - i; o++, j++)
        new[j] = buffer[o];
    new[len - i] = '\0';
    return (new);
}

char **formating(char *new)
{
    char **array;
    int lines = 0;
    int columns = 0;

    for (int i = 0; new[i] != '\0'; i++)
        if (new[i] == '\n')
            lines++;
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

    for (i = 0; char_map[i] != NULL; i++) {
        int_map[i + 1] = malloc(sizeof(int) * (columns + 2));
        int_map[i + 1][0] = 0;
        for (j = 0; char_map[i][j] != '\n'; j += 1)
            if (char_map[i][j] == 'o')
                int_map[i + 1][j + 1] = 0;
            else if (char_map[i][j] == '.')
                int_map[i + 1][j + 1] = 1;
        int_map[i + 1][columns + 1] = -1;
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

    if (int_map == NULL)
        return (NULL);
    for (columns = 0; char_map[0][columns] != '\n'; columns++);
    int_map[0] = malloc(sizeof(int) * (columns + 2));
    for (c = 0; c < columns; c++)
        int_map[0][c] = 0;
    int_map[0][c + 1] = -1;
    int_map = get_int_map2(char_map, int_map, columns);
    return (int_map);
}