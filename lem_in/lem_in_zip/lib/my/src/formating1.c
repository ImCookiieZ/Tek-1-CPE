/*
** EPITECH PROJECT, 2019
** karl-erik stoerzel
** File description:
** project
*/

#include "../include/struct.h"

my_params va_format_number(char *str, my_params params)
{
    int i;

    params.max = my_getnbr2(str, params.place);
    params.pre = 'n';
    for (i = params.place; str[i] != '\0' && (str[i] == \
' ' || str[i] == '0' || str[i] == '+' || str[i] == '-'); \
i++);
    params.place = my_count_digits(params.max) + i;
    return (params);
}

void my_print_spaces(int max, char flag)
{
    if (flag == 's' || flag == 'c' || flag == 'S')
        for (int i = 0; i < max; i++)
            my_putchar(' ');
    else
        for (int i = 0; i < max; i++)
            my_putchar('0');
}

my_params va_format_spaces(char *str, my_params params)
{
    my_preflags *pre_flags = my_get_preflags();

    params.place++;
    params.plus = ' ';
    for (int i = 0; i < 14; i++)
        if (str[params.place] == pre_flags[i].flag)
            params = pre_flags[i].f(str, params);
    free(pre_flags);
    return (params);
}

my_params va_format_plus(char *str, my_params params)
{
    my_preflags *pre_flags = my_get_preflags();

    params.plus = '+';
    params.place++;
    for (int i = 0; i < 14; i++)
        if (str[params.place] == pre_flags[i].flag)
            params = pre_flags[i].f(str, params);
    free(pre_flags);
    return (params);
}

my_params va_format_minus(char *str, my_params params)
{
    my_preflags *pre_flags = my_get_preflags();

    params.plus = '-';
    params.place++;
    for (int i = 0; i < 14; i++)
        if (str[params.place] == pre_flags[i].flag)
            params = pre_flags[i].f(str, params);
    free(pre_flags);
    return (params);
}