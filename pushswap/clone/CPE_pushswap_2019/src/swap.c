/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "../include/push_swap.h"

void sa(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    int tmp;

    get_start_list(&(*list_a), &(*list_b), *heads);
    if (*list_a != NULL && (*list_a)->next != NULL) {
        tmp = (*list_a)->nb;
        (*list_a)->nb = (*list_a)->next->nb;
        (*list_a)->next->nb = tmp;
        if (first)
            my_putstr("sa");
        else
            my_putstr(" sa");
    }
}

void sb(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    int tmp;

    get_start_list(&(*list_a), &(*list_b), *heads);
    if (*list_b != NULL && (*list_b)->next != NULL) {
        tmp = (*list_b)->nb;
        (*list_b)->nb = (*list_b)->next->nb;
        (*list_b)->next->nb = tmp;
        if (first)
            my_putstr("sb");
        else
            my_putstr(" sb");
    }
}

void sc(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    sa(&(*list_a), &(*list_b), &(*heads), first);
    sb(&(*list_a), &(*list_b), &(*heads), first);
}