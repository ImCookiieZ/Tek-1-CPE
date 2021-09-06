/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** add_all_includes
*/

#include "my.h"
#include "struct.h"

typedef struct my_round_para {
    int big;
    int one;
    int where;
}round_p_t;

typedef struct user_inputs {
    int max;
    int lines;
    int took_line;
    int took_mathces;
    int timeout;
    int player;
}user_inputs_t;

int final_round(char **map, user_inputs_t *ints);
int nim_method(char **map, user_inputs_t *ints, int i);
int ia_play(char **map, user_inputs_t *ints);
void check_my_input(char **map, user_inputs_t *ints);
int check_valid_line(char **map, user_inputs_t *ints);
void ais_turn(user_inputs_t *ints, char **map);
int get_matches_in_line(char const *line);
int get_max_moves(user_inputs_t *ints, char **map);
int check_end(char **map);
int my_error_checker(int ac, char **av);
int create_map(int lines, int max_take, int player);
char *my_fill_line(int count_lines, char *line);
char *draw_begin_line(int count_lines, int i, char *line);
char **edit_map(char **map, user_inputs_t ints);
int my_gameloop(user_inputs_t ints, char **map);
void check_valid(char **map, user_inputs_t *ints);
user_inputs_t *get_line_input(char **map, user_inputs_t *ints);
user_inputs_t *get_matches_input(char **map, user_inputs_t *ints);