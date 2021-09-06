/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "../include/push_swap.h"

void ra(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    list_t *tmp = (*heads)->start1;

    get_start_list(&(*list_a), &(*list_b), *heads);
    if ((*heads)->start1 && (*heads)->last1) {
        (*heads)->start1 = (*heads)->start1->next;
        (*heads)->last1 = tmp;
        get_start_list(&(*list_a), &(*list_b), *heads);
        if (first)
            my_putstr("ra");
        else
            my_putstr(" ra");
    }
}

void rb(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    list_t *tmp = (*heads)->start2;

    get_start_list(&(*list_a), &(*list_b), *heads);
    if ((*heads)->start2 && (*heads)->last2) {
        (*heads)->start2 = (*heads)->start2->next;
        (*heads)->last2 = tmp;
        get_start_list(&(*list_a), &(*list_b), *heads);
        if (first)
            my_putstr("rb");
        else
            my_putstr(" rb");
    }
}

void rr(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    ra(&(*list_a), &(*list_b), &(*heads), first);
    rb(&(*list_a), &(*list_b), &(*heads), first);
}
