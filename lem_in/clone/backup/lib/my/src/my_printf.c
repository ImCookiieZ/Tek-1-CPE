/*
** EPITECH PROJECT, 2019
** this is
** File description:
** printing
*/

#include "../include/struct.h"

int count_args(char *string)
{
    int len = my_strlen(string);
    int counter = 0;

    for (int i = 0; i < len; i++)
        if (string[i] == '%')
            counter++;
    return (counter);
}

int my_part_str(char *str, int i)
{
    for (; str[i] != '\0' && str[i] != '%'; i++)
        my_putchar(str[i]);
    return (i);
}

my_params pre_do(char *str, int *ar, my_prints *funcs, my_preflags *pre_flags)
{
    my_params params = {ar[1], 0, '\0', '\0', '\0'};

    for (int i = 0; i < 14; i++)
        if (str[ar[1]] == pre_flags[i].flag)
            params = pre_flags[i].f(str, params);
    return (params);
}

int *do_preflag(char *str, int *ar, va_list my_list)
{
    my_preflags *pre_flags = my_get_preflags();
    my_prints *funcs = get_my_prints(funcs);
    my_params params = pre_do(str, ar, funcs, pre_flags);

    for (int i = 0; i < 12; i++)
        if (str[params.place] == funcs[i].flag) {
            if (str[params.place] == '%')
                ar[0]--;
            ar[1] = funcs[i].f(my_list, str, params);
            free(funcs);
            free(pre_flags);
            return (ar);
        }
    if (str[params.place] != '\0')
        my_putchar('%');
    ar[0]--;
    ar[1]--;
    free(funcs);
    free(pre_flags);
    return (ar);
}

int my_printf(char *str, ...)
{
    va_list my_va_list;
    int *ar = malloc(sizeof(int) * 2);

    ar[0] = count_args(str);
    ar[1] = my_part_str(str, 0);
    va_start(my_va_list, str);
    for (int i = 1; ar[1]++, i <= ar[0]; i++, ar[1] = my_part_str(str, ++ar[1]))
        ar = do_preflag(str, ar, my_va_list);
    va_end(my_va_list);
    free(ar);
    return (0);
}