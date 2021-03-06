/*
** EPITECH PROJECT, 2019
** y
** File description:
** k
*/

#include "include/my.h"

int my_end_sign(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] != '+' && str[i] != '-')
            return (i);
    }
    return (0);
}

int my_str_isnum(char const *str)
{
    for (int i = my_end_sign(str); str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}
