/*
** EPITECH PROJECT, 2020
** add_project_name
** File description:
** main.c
*/

#include <zconf.h>
#include "../include/all_includes.h"

int **prepare_int_array(int width, int height)
{
    int **visited = malloc(sizeof(int *) * (height + 1));

    if (visited == NULL)
        my_error_exit("whole visited array malloc failed\n");
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

head_t *backtrack_path(coord_t *cur)
{
    head_t *path = malloc(sizeof(coord_t));
    coord_t *iter = malloc(sizeof(coord_t));

    iter->x = cur->x;
    iter->y = cur->y;
    iter->prev = cur->prev;
    iter->len = cur->len;
    while (iter != NULL) {
        my_push(iter, path);
        iter = iter->prev;
    }
    return (path);
}

int my_get_file_len(int ac, char **av)
{
    int my_read = 0;
    int counter = 0;
    FILE *fd = NULL;
    char *line = NULL;
    size_t len;

    if (ac != 2)
        my_error_exit("wrong number of arguments\n");
    fd = fopen(av[1], "r");
    if (fd == NULL)
        my_error_exit("unable to open file\n");
    for (counter = 0; 1; counter++) {
        my_read = getline(&line, &len, fd);
        if (my_read == -1)
            break;
    }
    fclose(fd);
    return (counter);
}

char **get_map(char **map, FILE *fd, int counter)
{
    char *line = NULL;
    int my_read = 0;
    size_t buf_len;

    for (int i = 0; i < counter; i++) {
        my_read = getline(&line, &buf_len, fd);
        if (line[my_read - 1] == '\n')
            line[my_read - 1] = '\0';
        map[i] = my_strdup(line);
    }
    return (map);
}

int main(int ac, char **av)
{
    int counter = my_get_file_len(ac, av);
    FILE *fd = NULL;
    char *line = NULL;
    char **map = NULL;

    map = malloc(sizeof(char *) * (counter + 1));
    fd = fopen(av[1], "r");
    if (fd == NULL)
        my_error_exit("unable to open file\n");
    map = get_map(map, fd, counter);
    fclose(fd);
    map[counter] = NULL;
    if (map[0][0] == 'X' || map[counter - 1][my_strlen(map[0]) - 1] == 'X' ||
    bfs_new(map, my_strlen(map[0]), counter) == 0)
        my_printf("no solution found\n");
    free(line);
    return (0);
}