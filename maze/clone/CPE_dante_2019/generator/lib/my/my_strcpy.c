/*
** EPITECH PROJECT, 2019
** task 01
** File description:
** day 06
*/

#include "include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    unsigned i;

    for (i = 0; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
