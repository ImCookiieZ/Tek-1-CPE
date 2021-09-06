/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** final.c
*/

#include "../include/all_includes.h"

void one_is_pair(char **map, user_inputs_t *ints, int where)
{
    if (get_matches_in_line(map[where]) <= ints->max) {
        ints->took_mathces = get_matches_in_line(map[where]) - 1;
    } else
        ints->took_mathces = 1;
}

void one_is_not_pair(char **map, user_inputs_t *ints, int where)
{
    if (get_matches_in_line(map[where]) <= ints->max) {
        ints->took_mathces = get_matches_in_line(map[where]);
    } else
        ints->took_mathces = 1;
}

int find_final_solution(char **map, user_inputs_t *ints, round_p_t para)
{
    if (para.big == 1) {
        ints->took_line = para.where;
        if (para.one % 2 == 0)
            one_is_pair(map, ints, para.where);
        else
            one_is_not_pair(map, ints, para.where);
        return (2);
    }
    return (0);
}

int final_round(char **map, user_inputs_t *ints)
{
    round_p_t para = {0, 0, 0};

    for (int i = 1; i <= ints->lines; i++) {
        if (get_matches_in_line(map[i]) == 1)
            para.one++;
        if (get_matches_in_line(map[i]) > 1) {
            para.big++;
            para.where = i;
        }
    }
    if (find_final_solution(map, ints, para) == 2)
        return (2);
    return (0);
}