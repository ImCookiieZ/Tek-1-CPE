/*
** EPITECH PROJECT, 2019
** o
** File description:
** task 01
*/

#include "include/my.h"

void my_swap(int *a, int *b)
{
    int  temp = 0;
    int *pnttemp = &temp;

    *pnttemp = *a;
    *a = *b;
    *b = *pnttemp;
}
