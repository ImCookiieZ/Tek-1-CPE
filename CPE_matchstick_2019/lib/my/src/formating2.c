/*
** EPITECH PROJECT, 2019
** karl-erik stoerzel
** File description:
** project
*/

#include "../include/struct.h"

my_params va_format_hashtack(char *str, my_params params)
{
    my_preflags *pre_flags = my_get_preflags();

    params.place++;
    params.plus2 = '#';
    for (int i = 0; i < 14; i++)
        if (str[params.place] == pre_flags[i].flag)
            params = pre_flags[i].f(str, params);
    free(pre_flags);
    return (params);
}

char *my_get_hexa1(unsigned int nb, int len, my_params params, char *res)
{
    for (int i = 0; i < len; i++)
        res[i] = '0';
    res[len] = '\0';
    for (int i = 1; nb > 0; i++) {
        res[len - i] = nb % 16 + 48;
        if (res[len - i] > '9')
            res[len - i] = res[len - i] - '9' + 'A' - 1;
        nb /= 16;
    }
    return (res);
}

int va_put_hexa1(va_list my_list, char *string, my_params params)
{
    unsigned int nb = va_arg(my_list, unsigned int);
    int len = count_digits(nb);
    char *res = malloc(sizeof(char) * (len + 1));
    char *new;
    int i = 0;

    if (params.plus2 == '#')
        i += 2;
    res = my_get_hexa1(nb, len, params, res);
    new = my_delete_zeros2(res);
    modifyer_call(params, my_strlen(new) + i, 'X', new);
    free(res);
    free(new);
    return (params.place);
}

void modifyer_call(my_params params, int len, char flag, char *str)
{
    if (params.pre != '0')
        my_modify(params, len, flag, 0);
    if (params.plus2 == '#' && flag == 'o')
        my_putchar('0');
    if (params.plus2 == '#' && (flag == 'x' || flag == 'X' || flag == 'p'))
            my_putstr("0x");
    else if (flag == 'p')
        my_putstr("0x");
    if (params.pre == '0')
        my_modify(params, len, flag, 0);
    my_putstr(str);
    params.max *= -1;
    my_modify(params, len , flag, 1);
}
