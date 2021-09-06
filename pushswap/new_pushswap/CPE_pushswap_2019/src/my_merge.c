/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "../include/push_swap.h"

void get_begin(list_t **list_a, list_t **list_b, head_t **head_list)
{
    int counter = 0;

    while ((*list_a)->nb > (*list_a)->before->nb) {
        (*list_a) = (*list_a)->before;
        counter++;
    }
    if (counter < (*head_list)->len1 / 2) {
        for (int i = 0; i < counter; i++)
            rra(&(*list_a), &(*list_b), &(*head_list), 0);
    }
    else if (counter >= (*head_list)->len1 / 2) {
        for (int i = 0; i < (*head_list)->len1 - counter; i++)
            ra(&(*list_a), &(*list_b), &(*head_list), 0);
    }
}

void my_merge(list_t **list_a, list_t **list_b, head_t **head_list)
{
    int counter = 0;
    while ((*head_list)->start2) {
        get_start_list(&(*list_a), &(*list_b), *head_list);
        if ((*head_list)->start2->nb >= (*head_list)->last1->nb &&
            (*head_list)->start2->nb > (*head_list)->start1->nb) {
            pa(&(*list_a), &(*list_b), &(*head_list), 0);
            ra(&(*list_a), &(*list_b), &(*head_list), 0);
            continue;
        }
        while (1) {
            if ((*head_list)->start2->nb <= (*list_a)->nb && (*head_list)
            ->start2->nb >= (*list_a)->before->nb) {
                break;
            }
            if (counter == (*head_list)->len1)
                break;
            (*list_a) = (*list_a)->next;
            counter++;
        }
        get_start_list(&(*list_a), &(*list_a), *head_list);
        if (counter < (*head_list)->len1 / 2) {
            for (int i = 0; i < counter; i++)
                ra(&(*list_a), &(*list_b), &(*head_list), 0);
            pa(&(*list_a), &(*list_b), &(*head_list), 0);
        }
        else if (counter >= (*head_list)->len1 / 2) {
            for (int i = 0; i < (*head_list)->len1 - counter; i++)
                rra(&(*list_a), &(*list_b), &(*head_list), 0);
            pa(&(*list_a), &(*list_b), &(*head_list), 0);
        }
        counter = 0;
    }
    get_begin(&(*list_a), &(*list_b), &(*head_list));
}