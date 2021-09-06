/*
** EPITECH PROJECT, 2019
** task 06
** File description:
** if it is prime
*/

#include "include/my.h"

int my_is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    if (nb == 2)
        return (1);
    for (int i = 2; i <= nb / 2; i++) {
        for (int j = 2; j <= i; j++) {
            if (i * j == nb)
                return (0);
        }
    }
    return (1);
}
