/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** preparation.c
*/

#include "../include/all_includes.h"

char *draw_begin_line(int count_lines, int i, char *line)
{
    int stars = i * 2 - 1;
    int half = ((count_lines * 2 - 1) - stars) / 2;

    line = malloc(sizeof(char) * (half * 2 + stars + 4));
    line[0] = '*';
    for (int j = 0; j < half; j++)
        line[j + 1] = ' ';
    for (int j = 0; j < stars; j++)
        line[j + half + 1] = '|';
    for (int j = 0; j < half; j++)
        line[j + half + stars + 1] = ' ';
    line[half * 2 + stars + 1] = '*';
    line[half * 2 + stars + 2] = '\n';
    line[half * 2 + stars + 3] = '\0';
    return (line);
}

char *my_fill_line(int count_lines, char *line)
{
    line = malloc(sizeof(char) * (count_lines * 2 + 3));
    line = my_memset(line, count_lines * 2 + 1, '*');
    line[count_lines * 2 + 1] = '\n';
    line[count_lines * 2 + 2] = '\0';
    return (line);
}

int create_map(int lines, int max_take, int player)
{
    user_inputs_t my_ints = {max_take, lines, 0, 0, 0, player};
    char **map = malloc(sizeof(char *) * (lines + 3));

    map[0] = my_fill_line(lines, map[0]);
    for (int i = 1; i <= lines; i++) {
        map[i] = draw_begin_line(lines, i, map[i]);
    }
    map[lines + 1] = my_fill_line(lines, map[lines]);
    map[lines + 2] = NULL;
    return (my_gameloop(my_ints, map));
}

int my_error_checker(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (my_str_isnum(av[i]) == 0)
            return (84);
    }
    if (my_getnbr(av[2]) <= 0)
        return (84);
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 100)
        return (84);
    return (0);
}