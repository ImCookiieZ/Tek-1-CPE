/*
** EPITECH PROJECT, 2019
** y
** File description:
** nothing
*/

#include "include/my.h"

char *my_memset(char *str, int size, char c)
{
    for (int i = 0; i < size; i++)
        str[i] = c;
    return (str);
}