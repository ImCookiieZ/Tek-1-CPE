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

void pb(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    get_start_list(&(*list_a), &(*list_b), *heads);
    if (*list_a) {
        if ((*heads)->start1 == (*heads)->last1)
            (*heads)->last1 = NULL;
        else
            (*heads)->start1 = (*list_a)->next;
        (*heads)->start2 = (*list_a);
        (*heads)->last1->next = (*list_a)->next;
        (*list_a)->next = *list_b;
        if (*list_b)
            (*list_b)->before = *list_a;
        if (first)
            my_putstr("pb");
        else
            my_putstr(" pb");
    }
    get_start_list(&(*list_a), &(*list_b), *heads);
}

void pa(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    get_start_list(&(*list_a), &(*list_b), *heads);
    if (*list_b) {
        if ((*heads)->start2 == (*heads)->last2)
            (*heads)->last2 = NULL;
        else
            (*heads)->start2 = (*list_b)->next;
        (*heads)->start1 = (*list_b);
        (*heads)->last1->next = (*list_a)->next;
        (*list_b)->next = *list_a;
        if (*list_b)
            (*list_b)->before = *list_a;
        if (first)
            my_putstr("pa");
        else
            my_putstr(" pa");
    }
    get_start_list(&(*list_a), &(*list_b), *heads);
}