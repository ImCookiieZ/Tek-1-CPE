/*
** EPITECH PROJECT, 2019
** nothing
** File description:
** nothing
*/

#include "include/my.h"

char *my_strdup(char *src)
{
    char *dest = NULL;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(dest, src);
    dest[my_strlen(src)] = '\0';
    return (dest);
}
