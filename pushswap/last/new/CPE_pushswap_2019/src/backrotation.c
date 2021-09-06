/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "../include/push_swap.h"

void rra(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    get_start_list(&(*list_a), &(*list_b), *heads);
    if ((*heads)->start1 && (*heads)->last1) {
        (*heads)->start1 = (*heads)->last1;
        (*heads)->last1 = (*heads)->last1->before;
        get_start_list(&(*list_a), &(*list_b), *heads);
        if (first)
            my_putstr("rra");
        else
            my_putstr(" rra");
    }
}

void rrb(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    get_start_list(&(*list_a), &(*list_b), *heads);
    if ((*heads)->start2 && (*heads)->last2) {
        (*heads)->start2 = (*heads)->last2;
        (*heads)->last2 = (*heads)->last2->before;
        get_start_list(&(*list_a), &(*list_b), *heads);
        if (first)
            my_putstr("rrb");
        else
            my_putstr(" rrb");
    }
}

void rrr(list_t **list_a, list_t **list_b, head_t **heads, int first)
{
    rra(&(*list_a), &(*list_b), &(*heads), first);
    rrb(&(*list_a), &(*list_b), &(*heads), first);
}