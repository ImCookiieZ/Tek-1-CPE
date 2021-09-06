/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** my_str_case.c
*/

#include "../include/all_includes.h"

char *my_strlowercase(char *str)
{
    char *ret = my_strdup(str);

    for (int i = 0; ret[i]; i++) {
        if (ret[i] >= 'A' && ret[i] <= 'Z')
            ret[i] += ('a' - 'A');
    }
    return (ret);
}

char *my_struppercase(char *str)
{
    char *ret = my_strdup(str);

    for (int i = 0; ret[i]; i++) {
        if (ret[i] >= 'a' && ret[i] <= 'z')
            ret[i] -= ('a' - 'A');
    }
    return (ret);
}