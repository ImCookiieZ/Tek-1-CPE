/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "../include/push_swap.h"

int my_sorted_check(list_t *list_a, list_t *list_b, head_t *heads)
{
    get_start_list(&list_a, &list_b, heads);
    if (list_a) {
        while (list_a != heads->last1) {
            if (list_a->nb > list_a->next->nb)
                return (0);
            list_a = list_a->next;
        }
    }
    if (!(list_b))
        return (1);
    return (0);
}

void sort_a(list_t **list_a, list_t **list_b, head_t **head_list, int first)
{
    if ((*list_a)->nb > (*list_a)->next->nb) {
        sa(&(*list_a), &(*list_b), &(*head_list), first);
        while (*list_b)
            pa(&(*list_a), &(*list_b), &(*head_list), first);
    }
    else if ((*head_list)->start1->nb > (*head_list)->last1->nb) {
        rra(&(*list_a), &(*list_b), &(*head_list), first);
        while (*list_b)
            pa(&(*list_a), &(*list_b), &(*head_list), first);
    }
    else
        pb(&(*list_a), &(*list_b), &(*head_list), first);
}

void  sort_b(list_t **list_a, list_t **list_b, head_t **head_list, int first)
{
    if ((*head_list)->start2->nb < (*list_b)->before->nb)
        rrb(&(*list_a), &(*list_b), &(*head_list), first);
    if ((*head_list)->start2->nb < (*head_list)->start2->next->nb)
        sb(&(*list_a), &(*list_b), &(*head_list), first);
}

list_t *my_sort(list_t *list_a, list_t *list_b, head_t *head_list)
{
    int first = 1;
    while (!(my_sorted_check(list_a, list_b, head_list))) {
        if (list_b && list_b->next) {
            sort_b(&list_a, &list_b, &head_list, first);
        }
        if (list_a && list_a->next) {
            sort_a(&list_a, &list_b, &head_list, first);
        }
        first = 0;
    }
    end_prining(list_a, list_b, head_list);
    return (list_a);
}