/*
** EPITECH PROJECT, 2019
** task04
** File description:
** power rec
*/

#include "include/my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p >= 0)
        return (nb * my_compute_power_rec(nb, p - 1));
}
