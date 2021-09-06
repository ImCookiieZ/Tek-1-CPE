/*
** EPITECH PROJECT, 2019
** task 01
** File description:
** day 06
*/

#include "include/my.h"

char *my_strcpy2(char *dest, char const *src)
{
    unsigned i;

    for (i = 0; src[i] && src[i] != '\n'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strcpy(char *dest, char const *src)
{
    unsigned i;

    for (i = 0; src[i]; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
