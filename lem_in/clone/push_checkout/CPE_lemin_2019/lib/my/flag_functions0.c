/*
** EPITECH PROJECT, 2019
** funktions
** File description:
** per_char
*/

#include "../include/struct.h"

int va_putchar(va_list my_list, char *string, my_params params)
{
    int c = va_arg(my_list, int);

    my_modify(params, 1, 'c', 0);
    my_putchar(c);
    params.max *= -1;
    my_modify(params, 1, 'c', 1);
    return (params.place);
}

int va_putstr(va_list my_list, char *string, my_params params)
{
    char *str = va_arg(my_list, char *);

    my_modify(params, my_strlen(str), 's', 0);
    my_putstr(str);
    params.max *= -1;
    my_modify(params, my_strlen(str), 's', 1);
    return (params.place);
}

void do_function(int nbr, char *string, my_params params, int i)
{
    if (params.plus == '+' || nbr < 0 || params.plus == ' ') {
        i++;
        small_do_function(nbr, string, params, i);
        if (nbr >= 0 && params.plus == ' ')
            my_putchar(' ');
        if (nbr < 0) {
            nbr *= -1;
            my_putchar('-');
            if (params.pre == '0')
                my_modify(params, my_count_digits(nbr) + i, 'd', 0);
        }
    }
    else
        my_modify(params, my_count_digits(nbr) + i, 'd', 0);
    my_put_nbr(nbr);
    params.max *= -1;
    my_modify(params, my_count_digits(nbr) + i, 'd', 1);
}

int va_put_nbr(va_list my_list, char *string, my_params params)
{
    int nbr = va_arg(my_list, int);
    int i = 0;

    do_function(nbr, string, params, i);
    return (params.place);
}

int va_putstr2(va_list my_list, char *string, my_params params)
{
    char *str = va_arg(my_list, char *);
    int len = my_strlen(str);

    my_modify(params, len, 'S', 0);
    for (int i = 0; i < len; i++)
        if (str[i] > 31 && str[i] < 127)
            my_putchar(str[i]);
        else if (str[i] >= 1)
            my_putoctal(str[i]);
        else
            my_putstr("\000");
    params.max *= -1;
    my_modify(params, len, 'S', 1);
    return (params.place);
}