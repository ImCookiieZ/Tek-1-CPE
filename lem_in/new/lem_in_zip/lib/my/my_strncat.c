/*
** EPITECH PROJECT, 2019
** y
** File description:
** nothing
*/

#include "include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int len = my_strlen(dest);

    for (i = len; i < nb + len && src[i - len]; i++)
        dest[i] = src[i - len];
    dest[i + len] = '\0';
    return (dest);
}