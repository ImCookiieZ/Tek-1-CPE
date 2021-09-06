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

void help_printing(void)
{
    my_printf("Usage:\n\t./matchstick [lines] [max stick removeable] \
    [players]\n");
    my_printf("\t\tlines: lines must be minimum two and maximal 99\n");
    my_printf("\t\tremovable: says how many sticks you can remove maximal. \
    minimum is always 1\n");
    my_printf("\t\tplayer:\n\t\t\t");
    my_printf("says how many humans will play.\n\t\t\t");
    my_printf("if no argument is given it is 1.\n");

}

int main(int ac, char **av)
{
    int ret = 0;
    int player = 1;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        help_printing();
    else if (ac != 3 && ac != 4)
        ret = 84;
    else
        ret = my_error_checker(ac, av);
    if (ret == 0 && ac == 4)
        player = my_getnbr(av[3]);
    if (player != 1)
        my_printf("Player 2 begins\n");
    if (ret == 0 && (ac == 4 || ac == 3))
        ret = create_map(my_getnbr(av[1]), my_getnbr(av[2]), player);
    if (ret == 1 && player == 1 && (ac == 4 || ac == 3))
        my_printf("I lost... snif... but I'll get you next time!!\n");
    if (ret == 2 && player == 1) my_printf("You lost, too bad...\n");
    else if (ret != 84 && (player == 2 || player == 0))
        my_printf("Player %i lost\n", ret);
    return (ret);
}