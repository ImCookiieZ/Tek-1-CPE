/*
** EPITECH PROJECT, 2019
** karl-erik stoerzel
** File description:
** project
*/

#include "../include/struct.h"

void small_do_function(int nbr, char *string, my_params params, int i)
{
    if (params.pre != '0')
        my_modify(params, my_count_digits(nbr) + i, 'd', 0);
    if (nbr >= 0 && params.plus == '+')
        my_putchar('+');
}