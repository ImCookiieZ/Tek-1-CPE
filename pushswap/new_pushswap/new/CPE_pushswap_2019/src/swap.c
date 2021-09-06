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

void null_pb(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    int tmp = (*list_a)->nb;

    free(*list_a);
    *list_b = malloc(sizeof(list_t));
    (*list_b)->next = (*list_b);
    (*list_b)->before = (*list_b);
    (*list_b)->nb = tmp;
    (*heads)->start2 = *list_b;
    (*heads)->last2 = (*list_b);
    my_putstr("pb");
}

void pb(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    int tmp = (*list_a)->nb;

    get_start_list(&(*list_a), &(*list_b), *heads);
    if (*list_a) {
        (*heads)->start1 = (*list_a)->next;
        (*heads)->start1->before = (*list_a)->before;
        (*heads)->last1->next = (*heads)->start1;
        if (((*heads)->start2) == NULL)
            null_pb(&(*list_a), &(*list_b), &(*heads), first);
        else {
            (*list_a)->next = (*heads)->start2;
            (*list_a)->before = (*heads)->last2;
            (*heads)->start2 = (*list_a);
            my_putstr(" pb");
        }
    }
}

void null_pa(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    int tmp = (*list_b)->nb;

    free(*list_b);
    *list_a = malloc(sizeof(list_t));
    (*list_a)->next = (*list_a);
    (*list_a)->before = (*list_a);
    (*list_a)->nb = tmp;
    (*heads)->start1 = *list_a;
    (*heads)->last1 = (*list_a);
    my_putstr(" pa");
}

void pa(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    get_start_list(&(*list_a), &(*list_b), *heads);
    if (*list_b) {
        if ((*heads)->start2 == (*heads)->last2)
            (*heads)->start2 = NULL;
        else {
            (*heads)->start2 = (*list_b)->next;
            (*heads)->start2->before = (*list_b)->before;
            (*heads)->last2->next = (*heads)->start2;
        }
        if (((*heads)->start1) == NULL)
            null_pa(&(*list_a), &(*list_b), &(*heads), first);
        else {
            (*list_b)->next = (*heads)->start1;
            (*list_b)->before = (*heads)->last1;
            (*heads)->start1 = (*list_b);
            my_putstr(" pa");
        }
    }
}