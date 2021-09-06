/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "../include/push_swap.h"

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
    list_t *tmp = (*heads)->start2;

    (*heads)->len2++;
    (*heads)->len1--;
    get_start_list(&(*list_a), &(*list_b), *heads);
    if (*list_a) {
        if ((*heads)->start1 == (*heads)->last1) {
            (*heads)->start1 = NULL;
            (*heads)->last1 = NULL;
        }
        else {
            (*heads)->start1 = (*list_a)->next;
            (*heads)->start1->before = (*list_a)->before;
            (*heads)->last1->next = (*heads)->start1;
        }
        if (((*heads)->start2) == NULL)
            null_pb(&(*list_a), &(*list_b), &(*heads), first);
        else {
            (*heads)->start2 = (*list_a);
            (*heads)->start2->before = (*heads)->last2;
            (*heads)->last2->next = (*heads)->start2;
            (*heads)->start2->next = tmp;
            (*heads)->start2->next->before = (*heads)->start2;
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
    (*heads)->len1++;
    (*heads)->len2--;
    get_start_list(&(*list_a), &(*list_b), *heads);
    if (*list_b) {
        if ((*heads)->start2 == (*heads)->last2) {
            (*heads)->start2 = NULL;
            (*heads)->last2 = NULL;
        }
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
            (*heads)->last1->next = (*heads)->start1;
            my_putstr(" pa");
        }
    }
}