/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** main.c
*/

#include "../include/all_includes.h"

void check_my_input(char **map, user_inputs_t *ints)
{
    if (ints->took_line == 0 || ints->took_line > ints->lines) {
        my_printf("Error: this line is out of range\n");
        get_line_input(map, ints);
    }
    else if (!(check_valid_line(map, ints))) {
        my_printf("Error: not enough matches on this line\n");
        get_line_input(map, ints);
    }
}

int get_matches_in_line(char const *line)
{
    int counter = 0;

    for (int i = 1; line[i] != '*'; i++)
        if (line[i] == '|')
            counter++;
    return (counter);
}

int get_max_moves(user_inputs_t *ints, char **map)
{
    int matches = 0;

    for (int i = 1; map[i]; i++) {
        matches += get_matches_in_line(map[i]);
    }
    return (matches);
}

int check_end(char **map)
{
    for (int i = 1; map[i][1] != '*'; i++) {
        for (int j = 1; map[i][j] != '*'; j++) {
            if (map[i][j] == '|') {
                return (0);
            }
        }
    }
    return (1);
}

int main(int ac, char **av)
{
    int ret = 0;
    if (ac != 3)
        ret = (84);
    else
        ret = my_error_checker(ac, av);
    if (ret == 0)
        ret = create_map(my_getnbr(av[1]), my_getnbr(av[2]));
    if (ret == 1)
        my_printf("I lost... snif... but I'll get you next time!!\n");
    else if (ret == 2)
        my_printf("You lost, too bad...\n");
    return (ret);
}