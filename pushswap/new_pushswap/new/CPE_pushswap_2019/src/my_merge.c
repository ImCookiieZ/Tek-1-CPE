/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "../include/push_swap.h"

void my_merge(list_t **list_a, list_t **list_b, head_t **head_list)
{
    int counter_ra = 0;
    int counter_rra = 0;

    while ((*head_list)->start2) {
        while ((*list_b)->nb > (*list_a)->nb && counter_ra < (*head_list)->ac
        / 2) {
            (*list_a) = (*list_a)->next;
            counter_ra++;
        }
        get_start_list(list_a, list_b, *head_list);
        while ((*list_b)->nb > (*list_a)->nb && counter_rra < (*head_list)->ac
        / 2) {
            (*list_a) = (*list_a)->before;
            counter_rra++;
        }
        get_start_list(list_a, list_a, *head_list);
        if (counter_ra < counter_rra) {
            for (int i = 0; i < counter_ra; i++)
                ra(&(*list_a), &(*list_b), &(*head_list), 0);
        }
        if (counter_ra >= counter_rra) {
            for (int i = 0; i < counter_rra; i++)
                rra(&(*list_a), &(*list_b), &(*head_list), 0);
        }
        pa(&(*list_a), &(*list_b), &(*head_list), 0);
        if (counter_ra < counter_rra) {
            for (int i = 0; i < counter_ra; i++)
                rra(&(*list_a), &(*list_b), &(*head_list), 0);
        }
        if (counter_ra >= counter_rra) {
            for (int i = 0; i < counter_rra; i++)
                ra(&(*list_a), &(*list_b), &(*head_list), 0);
        }
        get_start_list(list_a, list_b, *head_list);
    }
}