/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "../include/push_swap.h"

int my_sorted_check_list1(list_t *list_a, list_t *list_b, head_t *heads)
{
    get_start_list(&list_a, &list_b, heads);
    if (list_a) {
        while (list_a != heads->last1) {
            if (list_a->nb > list_a->next->nb)
                return (0);
            list_a = list_a->next;
        }
    }
    return (1);
}

int my_sorted_check_list2(list_t *list_a, list_t *list_b, head_t *heads)
{
    get_start_list(&list_a, &list_b, heads);
    if (list_b) {
        while (list_b != heads->last2) {
            if (list_b->nb < list_b->next->nb)
                return (0);
            list_b = list_b->next;
        }
    }
    return (1);
}

void sort_a(list_t **list_a, list_t **list_b, head_t **head_list)
{
    int j = 0;

    get_start_list(&(*list_a), &(*list_b), *head_list);
    while (!(my_sorted_check_list1(*list_a, *list_b, *head_list))) {
        for (int i = 1; i < (*head_list)->ac / 2 + (*head_list)->ac % 2; i++) {
            get_start_list(list_a, list_b, *head_list);
            if ((*list_a)->nb > (*list_a)->next->nb)
                sa(&(*list_a), &(*list_b), &(*head_list), 0);
            else {
                ra(&(*list_a), &(*list_b), &(*head_list), 0);
                j++;
            }
            if (my_sorted_check_list1(*list_a, *list_b, *head_list))
                return;
        }
        for (; j > 0; j--) {
            rra(&(*list_a), &(*list_b), &(*head_list), 0);
            if (my_sorted_check_list1(*list_a, *list_b, *head_list))
                return;
        }
    }
}

void sort_b(list_t **list_a, list_t **list_b, head_t **head_list)
{
    int j = 0;

    get_start_list(&(*list_a), &(*list_b), *head_list);
    while (!(my_sorted_check_list2(*list_a, *list_b, *head_list))) {
            for (int i = 1; i < (*head_list)->ac / 2; i++) {
                if ((*list_b)->nb < (*list_b)->next->nb) {
                    sb(&(*list_a), &(*list_b), &(*head_list), 0);
                }
                else {
                    rb(&(*list_a), &(*list_b), &(*head_list), 0);
                    j++;
                }
                if (my_sorted_check_list2(*list_a, *list_b, *head_list))
                    return;
            }
            for (; j > 0; j--) {
                rrb(&(*list_a), &(*list_b), &(*head_list), 0);
                if (my_sorted_check_list2(*list_a, *list_b, *head_list))
                    return;
            }
    }
}

list_t *my_sort(list_t *list_a, list_t *list_b, head_t *head_list)
{
    if (my_sorted_check_list1(list_a, list_b, head_list))
        return (list_a);
    for (int i = 0; i < head_list->ac / 2; i++)
        pb(&list_a, &list_b, &head_list, 1);
    if (list_b && list_b->next)
        sort_b(&list_a, &list_b, &head_list);
    if (list_a && list_a->next)
        sort_a(&list_a, &list_b, &head_list);
    my_merge(&list_a, &list_b, &head_list);
    return (list_a);
}