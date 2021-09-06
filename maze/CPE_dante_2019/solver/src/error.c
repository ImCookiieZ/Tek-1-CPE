/*
** EPITECH PROJECT, 2020
** generator
** File description:
** error.c
*/

#include "../include/all_includes.h"

void my_put_error_str(char *str)
{
    int i;
    for (i = 0; str[i]; i++);
    write(2, str, i);
}

void my_error_exit(char *error_msg)
{
    my_put_error_str(error_msg);
    exit(84);
}