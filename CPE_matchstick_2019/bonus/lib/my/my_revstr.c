/*
** EPITECH PROJECT, 2019
** task 03
** File description:
** nothing
*/

#include "include/my.h"

char *my_revstr(char *str)
{
    int     loop;
    int     str_len = my_strlen(str);
    char    temp;

    str_len = my_strlen(str);
    loop = str_len / 2;
    for (int i = 0; i != loop; i++) {
        temp = str[i];
        str[i] = str[str_len - i - 1];
        str[str_len - i - 1] = temp;
    }
    return (str);
}
