/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** new_class.c
*/

#include "../include/all_includes.h"

int get_nim_res(char **map, user_inputs_t *ints, int j, int neg)
{
    int ret = 0;

    for (int i = 1; i <= ints->lines; i++) {
        if (i == neg)
            ret ^= (get_matches_in_line(map[i]) - j);
        else
            ret ^= get_matches_in_line(map[i]);
    }
    return (ret);
}

int ia_play(char **map, user_inputs_t *ints)
{
    int j = 1;

    if (final_round(map, ints) == 2)
        j = 0;
    for (int i = 1; i <= ints->lines && j == 1; i++) {
        if (nim_method(map, ints, i + 1) == 2)
            j = 0;
    }
    return (j);
}

int nim_method(char **map, user_inputs_t *ints, int i)
{
    int j = 1;

    if (get_matches_in_line(map[i]) == 0)
        return (1);
    for (; j <= get_matches_in_line(map[i]) && j <= ints->max; j++) {
        if (get_nim_res(map, ints, j, i) == 0) {
            ints->took_line = i;
            ints->took_mathces = j;
            return (2);
        }
    }
    return (0);
}