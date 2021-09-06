/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "../include/push_swap.h"

void get_begin(list_t **list_a, list_t **list_b, head_t **head_list)
{
    int tmp = (*head_list)->start1->nb;

    for (int i = 0; i < (*head_list)->len1; i++) {
        if ((*list_a)->nb < tmp)
            tmp = (*list_a)->nb;
        *list_a = (*list_a)->next;
    }
    get_start_list(&(*list_a), &(*list_b), *head_list);
    printf("start : %i tmp: %i", (*head_list)->start1->nb, tmp);
    while ((*head_list)->start1->nb > tmp)
        ra(&(*list_a), &(*list_b), &(*head_list), 0);
    return;
}

void my_merge(list_t **list_a, list_t **list_b, head_t **head_list)
{
    int counter = 0;
    int min = (*head_list)->start1->nb;
    int nb = 0;

    end_prining(*list_a, *list_b, *head_list);
    while ((*head_list)->start2) {
        get_start_list(&(*list_a), &(*list_b), *head_list);
        if ((*head_list)->start2->nb < min) {
            while ((*list_a)->nb != min) {
                my_put_nbr((*list_a)->nb);
                my_putstr("<-list a\ncounter:");
                (*list_a) = (*list_a)->next;
                counter++;
                nb = 1;
                my_put_nbr(counter);
            }
            min = (*head_list)->start2->nb;
        }
        get_start_list(&(*list_a), &(*list_b), *head_list);
        while (!(nb)) {
            if ((*head_list)->start2->nb <= (*list_a)->nb && (*head_list)
            ->start2->nb > (*list_a)->before->nb) {
                break;
            }
            if (counter == (*head_list)->len1) {
                break;
            }
            (*list_a) = (*list_a)->next;
            counter++;
        }
        get_start_list(&(*list_a), &(*list_a), *head_list);
        if (counter <= (*head_list)->len1 / 2) {
            for (int i = 0; i < counter; i++)
                ra(&(*list_a), &(*list_b), &(*head_list), 0);
            pa(&(*list_a), &(*list_b), &(*head_list), 0);
        }
        else if (counter > (*head_list)->len1 / 2) {
            for (int i = 0; i < (*head_list)->len1 - counter; i++)
                rra(&(*list_a), &(*list_b), &(*head_list), 0);
            pa(&(*list_a), &(*list_b), &(*head_list), 0);
        }
        counter = 0;
        nb = 0;
    }
    for (int i = 0; i < (*head_list)->len1; i++) {
        my_put_nbr((*list_a)->nb);
        my_putchar(' ');
        (*list_a) = (*list_a)->next;
    }
    end_prining(*list_a, *list_b, *head_list);
    get_begin(&(*list_a), &(*list_b), &(*head_list));
    end_prining(*list_a, *list_b, *head_list);
}