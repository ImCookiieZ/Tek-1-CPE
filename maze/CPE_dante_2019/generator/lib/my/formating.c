/*
** EPITECH PROJECT, 2019
** karl-erik stoerzel
** File description:
** project
*/

#include "../include/struct.h"

void my_print_zeros(int max, char flag, int call)
{
    if ((flag == 's' || flag == 'c' || flag == 'S' || call == 1) && max > 0) {
        for (int i = 0; i < max; i++)
            my_putchar(' ');
    }
    else if (max > 0) {
        for (int i = 0; i < max; i++)
            my_putchar('0');
    }
}

void my_print_number(int max, char flag, int call)
{
    for (int i = 0; i < max; i++)
        my_putchar(' ');
}

my_pre_functions *my_get_preflags_second(void)
{
    my_pre_functions *structure = malloc(sizeof(my_preflags) * 3);

    structure[0].f = my_print_zeros;
    structure[0].flag = '0';
    structure[1].f = my_print_number;
    structure[1].flag = 'n';
    structure[2].f = my_print_number;
    structure[2].flag = '-';
    return (structure);
}

void my_modify(my_params params, int len, char flag, int call)
{
    my_pre_functions *prints = my_get_preflags_second();

    for (int i = 0; i < 3; i++)
        if (prints[i].flag == params.pre && params.max < 0)
                prints[i].f(params.max + len, flag, call);
        else if (prints[i].flag == params.pre)
                prints[i].f(params.max - len, flag, call);
    free(prints);
}

my_params va_format_zero(char *str, my_params params)
{
    int i;

    params.pre = '0';
    params.max = my_getnbr2(str, params.place);
    for (i = params.place; str[i] != '\0' && (str[i] == \
' ' || str[i] == '0' || str[i] == '+' || str[i] == '-'); \
i++);
    if (params.max == 0)
        i--;
    params.place = my_count_digits(params.max) + i;
    return (params);
}