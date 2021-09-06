/*
** EPITECH PROJECT, 2019
** task06
** File description:
** insertionsort
*/

#include "../include/tmp.h"

int *my_sort_int_array(int *array, int size)
{
    int temp = 0;

    for (int i = 1; i < size; i++) {
        while ( i > 0 && array[i - 1] > array[i]) {
            temp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = temp;
            i--;
        }
    }
    return (array);
}

void my_putting(char **char_map)
{
    int a = 0;

    for (int j = 0; char_map[j] != NULL; j++) {
        for (int k = 0; char_map[j][k] != '\0'; k++)
            if (char_map[j][k] == 'x') {
                put_line(char_map[j]);
                k = 0;
                a = 1;
                break;
            }
        if (char_map[j] != NULL && a == 0)
            my_putstr(char_map[j]);
        a = 0;
    }
}

void put_line(char *line)
{
    for (int k = 0; line[k] != '\0'; k++)
        if (line[k] == 'x') {
            my_putstr("\033[33m");
            my_putchar(line[k]);
            my_putstr("\033[0m");
        }
        else
            my_putchar(line[k]);
}