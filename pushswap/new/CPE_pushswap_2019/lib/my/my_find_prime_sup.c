/*
** EPITECH PROJECT, 2019
** task 07
** File description:
** find smallest sub
*/

#include "include/my.h"

int my_find_prime_sup(int nb)
{
    if (nb <= 1)
        return (2);
    if (my_is_prime(nb) == 1)
        return (nb);
    nb++;
    for (int i = 2; i <= nb / 2; i++) {
        for (int j = 2; j <= i; j++) {
            if ( i * j == nb)
                return (my_find_prime_sup(nb));
        }
    }
    return (nb);
}
