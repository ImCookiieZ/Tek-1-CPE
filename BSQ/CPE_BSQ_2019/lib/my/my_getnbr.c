/*
** EPITECH PROJECT, 2019
** new
** File description:
** lol
*/

#include "include/my.h"

int pre_loop(char const *str, int i)
{
    while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
        i++;
    return (i);
}

int my_getnbr(char const *str)
{
    long nb = 0;
    int i = pre_loop(str, 0);
    int begin = i;
    int counter = 2;

    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        if (nb > 2147483647 || nb < -2147483647)
            return (0);
        i++;
    }
    while (begin != 0 && str[begin - 1] == '-') {
        counter++;
        begin--;
    }
    if (counter % 2 == 1)
        nb = nb * -1;
    return (nb);
}
