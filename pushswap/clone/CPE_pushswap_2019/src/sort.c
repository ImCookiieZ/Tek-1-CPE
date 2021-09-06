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

int get_turns(list_t *list_b, list_t *list_a, head_t *heads)
{
    int tmp = heads->start2->nb;
    int counter_ra = 0;
    int counter_rra = 0;

    list_b = list_b->next;
    while (list_b->nb > tmp && counter_ra < heads->len2) {
        list_b = list_b->next;
        counter_ra++;
    }
    get_start_list(&list_a, &list_b, heads);
    list_b = list_b->before;
    while (list_b->nb > tmp && counter_rra < heads->len2) {
        list_b = list_b->before;
        counter_rra--;
    }
    get_start_list(&list_a, &list_b, heads);
    end_prining(list_a, list_b, heads);
    printf("\ncounter ra: %i counter rra: %i\n\n", counter_ra, counter_rra);
    sleep(1);
    if (counter_ra < counter_rra * -1)
        return (counter_ra);
    return (counter_rra);
}

void sort_b(list_t **list_a, list_t **list_b, head_t **head_list)
{
    int j = 0;

    get_start_list(&(*list_a), &(*list_b), *head_list);
    while (!(my_sorted_check_list2(*list_a, *list_b, *head_list))) {
        if ((*head_list)->start2->nb < (*head_list)->start2->next->nb) {
            sb(&(*list_a), &(*list_b), &(*head_list), 0);
        }
        else {
            j = get_turns(*list_b, *list_a, *head_list);
            get_start_list(&(*list_a), &(*list_b), *head_list);
            if (j < 0) {
                for (int k = 0; k > j; k--)
                    rrb(&(*list_a), &(*list_b), &(*head_list), 0);
            }
            else if (j == 0)

            else
                for (int k = 0; k < j; k++)
                    rb(&(*list_a), &(*list_b), &(*head_list), 0);
        }
        j = 0;
        get_start_list(&(*list_a), &(*list_b), *head_list);
    }
}

list_t *my_sort(list_t *list_a, list_t *list_b, head_t *head_list)
{
    int *sorting = malloc(sizeof(int) * 2);

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