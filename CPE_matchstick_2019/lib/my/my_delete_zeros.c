/*
** EPITECH PROJECT, 2019
** s
** File description:
** d
*/

#include "../include/my.h"

char *my_delete_zeros(char *str)
{
    char *new;
    int i = 0;
    int j;

    while (str[i] != '\0' && str[i] == '0')
        i++;
    new = malloc(sizeof(char) * (my_strlen(str) - i + 2));
    for (j = 0; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {
        new[j] = str[i];
        j++;
    }
    new[j] = '\0';
    free(str);
    if (new[0] == '\0') {
        new[0] = '0';
        new[1] = '\0';
    }
    return (new);
}

char *my_delete_zeros2(char *str)
{
    char *new;
    int i = 0;
    int j;

    while (str[i] != '\0' && str[i] == '0')
        i++;
    new = malloc(sizeof(char) * (my_strlen(str) - i + 2));
    for (j = 0; str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9')     \
|| (str[i] >= 'a' && str[i] <= 'z') \
|| (str[i] >= 'A' && str[i] <= 'z')); i++) {
        new[j] = str[i];
        j++;
    }
    new[j] = '\0';
    free(str);
    if (new[0] == '\0') {
        new[0] = '0';
        new[1] = '\0';
    }
    return (new);
}