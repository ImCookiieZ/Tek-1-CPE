/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** find str
*/

#include "include/my.h"

char    *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        for (int k = 0; str[i + k] != '\0'; k++) {
            if (str[i + k] != to_find[k])
                break;
            if (to_find[k + 1] == '\0')
                return (&str[i]);
        }
    }
    return (0);
}
