/*
** EPITECH PROJECT, 2019
** task05
** File description:
** square root it
*/

#include "include/my.h"

int my_compute_square_root(int nb)
{
    int half = nb / 2;

    if (nb < 1)
        return (0);
    if (nb == 1)
        return (1);
    for (int i = 1; i <= half; i++) {
        if (i * i == nb) {
            return (i);
        }
    }
    return (0);
}
