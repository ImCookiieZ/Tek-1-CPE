/*
** EPITECH PROJECT, 2019
** f
** File description:
** g
*/

#include "include/my.h"

char    *my_strcat_char(char *src, char c)
{
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * (len + 2));

    dest = my_strcpy(dest, src);
    dest[len] = c;
    dest[len + 1] = '\0';
    return (dest);
}