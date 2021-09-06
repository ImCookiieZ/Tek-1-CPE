/*
** EPITECH PROJECT, 2019
** task 02
** File description:
** nothing
*/

#include "include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    write(1, str, i);
    return (0);
}
