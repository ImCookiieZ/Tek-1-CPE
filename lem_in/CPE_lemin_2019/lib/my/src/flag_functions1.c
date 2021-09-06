/*
** EPITECH PROJECT, 2019
** f
** File description:
** h
*/

#include "../include/struct.h"

char *my_get_hexa2(unsigned int nb, int len, my_params params, char *res)
{
    for (int i = 0; i < len; i++)
        res[i] = '0';
    res[len] = '\0';
    for (int i = 1; nb > 0; i++) {
        res[len - i] = nb % 16 + 48;
        if (res[len - i] > '9')
            res[len - i] = res[len - i] - '9' + 'a' - 1;
        nb /= 16;
    }
    return (res);
}

int va_put_hexa2(va_list my_list, char *string, my_params params)
{
    unsigned int nb = va_arg(my_list, unsigned int);
    int len = count_digits(nb);
    char *res = malloc(sizeof(char) * (len + 1));
    char *new;
    int i = 0;

    if (params.plus2 == '#')
        i += 2;
    res = my_get_hexa2(nb, len, params, res);
    new = my_delete_zeros2(res);
    modifyer_call(params, my_strlen(new) + i, 'x', new);
    free(res);
    free(new);
    return (params.place);
}

int va_putpercent(va_list my_list, char *string, my_params params)
{
    my_putchar('%');
    return (params.place);
}

int va_put_pointer(va_list my_list, char *string, my_params params)
{
    unsigned int nb = va_arg(my_list, unsigned int);
    int len = count_digits(nb);
    char *res = malloc(sizeof(char) * (len + 1));
    char *new;

    for (int i = 0; i < len; i++)
        res[i] = '0';
    res[len] = '\0';
    for (int i = 1; nb > 0; i++) {
        res[len - i] = nb % 16 + 48;
        if (res[len - i] > '9')
            res[len - i] = res[len - i] - '9' + 'a' - 1;
        nb /= 16;
    }
    new = my_delete_zeros2(res);
    modifyer_call(params, my_strlen(new) + 2, 'p', new);
    free(res);
    free(new);
    return (params.place);
}

void my_putoctal(int c)
{
    char *res = malloc(sizeof(char) * 5);

    for (int i = 1; i < 4; i++)
        res[i] = '0';
    res[0] = '\\';
    res[4] = '\0';
    for (int i = 0; c > 0; i++) {
        res[3 - i] = c % 8 + 48;
        c /= 8;
    }
    my_putstr(res);
    free(res);
}