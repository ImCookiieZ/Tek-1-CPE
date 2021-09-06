/*
** EPITECH PROJECT, 2019
** new
** File description:
** nothing
*/

#include "../include/my.h"

int my_count_digits(int nb)
{
    int counter;

    if (nb < 0)
        nb *= -1;
    for (counter = 0; nb > 9 || nb % 10 != 0; nb /= 10, counter++);
    if (counter == 0)
        return (1);
    return (counter);
}

int my_getnbr2(char const *str, int i)
{
    int left = 0;
    long nb = 0;

    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '-' || \
str[i] == '+' || str[i] == '0')) {
        if (str[i] == '-')
            left = 1;
        i++;
    }
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        if (nb > 2147483647 || nb < -2147483647)
            return (0);
        i++;
    }
    if (left == 1)
        nb *= -1;
    return (nb);
}