/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** game_loop.c
*/

#include "../include/all_includes.h"

int get_last_matchstick(char const *map)
{
    int end = 0;
    for (int i = 1; map[i] != '*'; i++) {
        if (map[i] == '|')
            end = i;
        else if (end != 0 && map[i] != '|')
            return end;
    }
    return (end);
}

char **edit_map(char **map, user_inputs_t ints)
{
    int i = get_last_matchstick(map[ints.took_line]);

    for (int j = 0; j < ints.took_mathces; j++)
        map[ints.took_line][i - j] = ' ';
    return (map);
}

void player_move(user_inputs_t *ints, char **map)
{
    for (int i = 0; map[i]; i++) my_printf(map[i]);
    my_printf("\nYour turn:\n");
    get_line_input(map, ints);
    get_matches_input(map, ints);
    if (ints->timeout == 0) my_printf("Player removed %i match(es) from line " \
    "%i\n", ints->took_mathces, ints->took_line);
}

void ai_move(user_inputs_t *ints, char **map)
{
    for (int i = 0; map[i]; i++) my_printf(map[i]);
    ais_turn(ints, map);
    my_printf("\nAI's turn...\n");
    my_printf("AI removed %i match(es) from line %i\n", \
            ints->took_mathces, ints->took_line);
}

int my_gameloop(user_inputs_t ints, char **map)
{
    int end = 0;
    int player = 1;

    while (end == 0 && ints.timeout == 0) {
        if ((player == 1 && ints.player == 1) || ints.player == 2) {
            player_move(&ints, map);
            if (player == 1) player = 2;
            else player = 1;
        }
        else if (ints.player != 2 && ints.timeout == 0) {
            ai_move(&ints, map);
            if (player == 2) player = 1;
            else player = 2;
        }
        if (ints.timeout == 0) {
            map = edit_map(map, ints);
            end = check_end(map);
        }
    }
    for (int i = 0; map[i] && ints.timeout == 0; i++) my_printf(map[i]);
    return (player);
}