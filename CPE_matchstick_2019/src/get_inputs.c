/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** get_inputs.c
*/

#include "../include/all_includes.h"

int check_valid_matches_2(char **map, user_inputs_t *ints)
{
    if (ints->took_mathces == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (0);
    }
    if (ints->took_mathces < 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (0);
    }
    if (ints->took_mathces > ints->max) {
        my_printf("Error: you cannot remove more than %i matches per turn\n",
            ints->max);
        return (0);
    }
    return (1);
}

int check_valid_matches(char **map, user_inputs_t *ints)
{
    int counter = 0;

    if (check_valid_matches_2(map, ints) == 0)
        return (0);
    for (int i = 1; map[ints->took_line][i] != '*'; i++)
        if (map[ints->took_line][i] == '|') counter++;
    if (counter < ints->took_mathces) {
        my_printf("Error: not enough matches on this line\n");
        return (0);
    }
    return (1);
}

user_inputs_t *get_matches_input(char **map, user_inputs_t *ints)
{
    char *user_input;

    if (ints->timeout == 0) my_printf("Matches: ");
    user_input = get_next_line(0);
    if (user_input == NULL) {
        ints->timeout = 1;
        return (ints);
    }
    else if (my_str_isnum(user_input)) {
        ints->took_mathces = my_getnbr(user_input);
        if (!(check_valid_matches(map, ints))) get_line_input(map, ints);
    }
    else {
        my_printf("Error: invalid input (positive number expected)\n");
        get_line_input(map, ints);
    }
    free(user_input);
    return (ints);
}

int check_valid_line(char **map, user_inputs_t *ints)
{
    int j = 1;

    for (int i = ints->took_line; map[i][j] != '*'; j++)
        if (map[i][j] == '|')
            return (1);
    return (0);
}

user_inputs_t *get_line_input(char **map, user_inputs_t *ints)
{
    char *user_input;

    if (ints->timeout == 0) my_printf("Line: ");
    user_input = get_next_line(0);
    if (user_input == NULL) {
        ints->timeout = 1;
        return (ints);
    }
    else if (my_str_isnum(user_input) && my_getnbr(user_input) >= 0) {
        ints->took_line = my_getnbr(user_input);
        check_my_input(map, ints);
    }
    else {
        my_printf("Error: invalid input (positive number expected)\n");
        get_line_input(map, ints);
    }
    free(user_input);
    return (ints);
}