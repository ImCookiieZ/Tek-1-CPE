/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** ai.c
*/

#include "../include/all_includes.h"

int get_lower_number(int nb1, int nb2)
{
    if (nb1 < nb2)
        return (nb1);
    else
        return (nb2);
}

int get_lines_with_matches(char **map)
{
    int counter = 0;
    int tmp_counter = 0;
    for (int i = 1; map[i]; i++) {
        for (int j = 1; map[i][j] != '*'; j++)
            if (map[i][j] == '|') {
                tmp_counter++;
            }
        if (tmp_counter == 1)
            counter++;
        tmp_counter = 0;
    }
    return (counter);
}

void ais_turn(user_inputs_t *ints, char **map)
{
    int matches = 0;

    if (ia_play(map, ints) != 1)
        return;
    for (int i = 1; map[i]; i++) {
        matches = get_matches_in_line(map[i]);
        for (int j = get_lower_number(ints->max, matches); \
    j > 0; j--) {
            if ((matches - j >= 0 && (matches - j) % 2 == 1) || \
        matches - j == 0) {
                ints->took_line = i;
                ints->took_mathces = j;
                return;
            }
        }
    }
    for (int i = 1; map[i]; i++)
        if (get_matches_in_line(map[i]) > 0)
            ints->took_line = i;
    ints->took_mathces = 1;
}