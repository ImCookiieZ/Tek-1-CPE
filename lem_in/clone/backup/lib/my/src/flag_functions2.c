/*
** EPITECH PROJECT, 2019
** f
** File description:
** h
*/

#include "../include/struct.h"

int count_digits(unsigned int nb)
{
    int i = 0;

    while (nb >= 10) {
        nb /= 10;
        i++;
    }
    return (i + 1);
}

int va_put_bin(va_list my_list, char *string, my_params params)
{
    unsigned int nb = va_arg(my_list, unsigned int);
    int len = count_digits(nb) * 4;
    char *res = malloc(sizeof(char) * (len + 1));
    char *new;

    for (int i = 0; i < len; i++)
        res[i] = '0';
    res[len] = '\0';
    for (int i = 1; nb > 0; i++) {
        res[len - i] = nb % 2 + 48;
        nb /= 2;
    }
    new = my_delete_zeros(res);
    my_modify(params, my_strlen(new), 'b', 0);
    my_putstr(new);
    params.max *= -1;
    my_modify(params, my_strlen(new), 'b', 1);
    free(res);
    free(new);
    return (params.place);
}

char *my_get_octa(unsigned int nb, int len, my_params params, char *res)
{
    for (int i = 0; i < len; i++)
        res[i] = '0';
    res[len] = '\0';
    for (int i = 1; nb > 0; i++) {
        res[len - i] = nb % 8 + 48;
        nb /= 8;
    }
    return (res);
}

int va_put_octal(va_list my_list, char *string, my_params params)
{
    unsigned int nb = va_arg(my_list, unsigned int);
    int len = count_digits(nb) * 2;
    char *res = malloc(sizeof(char) * (len + 1));
    char *new;
    int i = 0;

    if (params.plus2 == '#')
        i++;
    res = my_get_octa(nb, len, params, res);
    new = my_delete_zeros(res);
    modifyer_call(params, my_strlen(new) + i, 'o', new);
    free(res);
    free(new);
    return (params.place);
}

int va_put_u_nbr(va_list my_list, char *string, my_params params)
{
    unsigned int nb = va_arg(my_list, unsigned int);
    unsigned int mod = 0;

    my_modify(params, my_count_digits(nb), 'u', 0);
    if (nb >= 0) {
        if (nb >= 10) {
            mod = (nb % 10);
            nb = (nb - mod) / 10;
            my_put_nbr(nb);
            my_putchar(mod + 48);
        }
        else
            my_putchar(nb % 10 + 48);
    }
    params.max *= -1;
    my_modify(params, my_count_digits(nb), 'u', 1);
    return (params.place);
}