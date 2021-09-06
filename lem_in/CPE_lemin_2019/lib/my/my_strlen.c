/*
** EPITECH PROJECT, 2019
** task 05
** File description:
** y
*/

#include "include/my.h"

int my_arraylen(char **str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != NULL)
        i++;
    return (i);
}

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}
