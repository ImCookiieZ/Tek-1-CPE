/*
** EPITECH PROJECT, 2019
** structure
** File description:
** create
*/

#include "../include/struct.h"

my_preflags *my_get_preflags(void)
{
    my_preflags *structure = malloc(sizeof(my_prints) * 14);

    structure[0].f = va_format_zero;
    structure[0].flag = '0';
    structure[1].f = va_format_spaces;
    structure[1].flag = ' ';
    structure[2].f = va_format_number;
    structure[2].flag = '1';
    structure[3].f = va_format_number;
    structure[3].flag = '2';
    structure[4].f = va_format_number;
    structure[4].flag = '3';
    structure[5].f = va_format_number;
    structure[5].flag = '4';
    structure[6].f = va_format_number;
    structure[6].flag = '5';
    structure = my_get_preflags2(structure);
    return (structure);
}

my_preflags *my_get_preflags2(my_preflags *structure)
{
    structure[7].f = va_format_number;
    structure[7].flag = '6';
    structure[8].f = va_format_number;
    structure[8].flag = '7';
    structure[9].f = va_format_number;
    structure[9].flag = '8';
    structure[10].f = va_format_number;
    structure[10].flag = '9';
    structure[11].f = va_format_number;
    structure[11].flag = '-';
    structure[12].f = va_format_plus;
    structure[12].flag = '+';
    structure[13].flag = '#';
    structure[13].f = va_format_hashtack;
    return (structure);
}

my_prints *get_my_prints(void)
{
    my_prints *structure = malloc(sizeof(my_prints) * 12);
    structure[0].f = va_putchar;
    structure[0].flag = 'c';
    structure[1].f = va_put_nbr;
    structure[1].flag = 'd';
    structure[2].f = va_put_nbr;
    structure[2].flag = 'i';
    structure[3].f = va_putstr;
    structure[3].flag = 's';
    structure[4].f = va_put_octal;
    structure[4].flag = 'o';
    structure[5].f = va_put_hexa1;
    structure[5].flag = 'X';
    structure[6].f = va_put_bin;
    structure[6].flag = 'b';
    structure[7].flag = 'u';
    structure[7].f = va_put_u_nbr;
    structure = get_my_prints2(structure);
    return (structure);
}

my_prints *get_my_prints2(my_prints *structure)
{
    structure[8].f = va_put_hexa2;
    structure[8].flag = 'x';
    structure[9].f = va_putpercent;
    structure[9].flag = '%';
    structure[10].f = va_putstr2;
    structure[10].flag = 'S';
    structure[11].f = va_put_pointer;
    structure[11].flag = 'p';
    return (structure);
}