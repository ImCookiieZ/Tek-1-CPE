/*
** EPITECH PROJECT, 2019
** task06
** File description:
** insertionsort
*/

#include "../include/my.h"

int *my_sort_int_array(int *array, int size)
{
    int temp = 0;

    for (int i = 1; i < size; i++) {
        while (i > 0 && array[i - 1] > array[i]) {
            temp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = temp;
            i--;
        }
    }
    return (array);
}

int my_getnbr3(char *str)
{
    long nb = 0;
    int i = 0;

    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        if (nb > 2147483647 || nb < -2147483647)
            return (0);
        i++;
    }
    if (str[i] != '\n')
        return (0);
    return (nb);
}