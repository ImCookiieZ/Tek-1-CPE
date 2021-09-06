/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include "include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[len + i] = src[i];
        i += 1;
    }
    dest[len + i] = '\0';
    return (dest);
}
