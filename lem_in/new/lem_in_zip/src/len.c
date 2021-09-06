/*
** EPITECH PROJECT, 2020
** lem_in
** File description:
** len.c
*/

#include "../include/all_includes.h"

int get_max_value(possible_ways_head_t *head, int max)
{
    possible_ways_stack_t *tmp = head->start;

    int count = 0;
    int ants = 0;

    //todo: find cause of valgrind error caused by "max"
    while (tmp) {
        if (tmp->cur->len < max) {
            count = tmp->cur->len;
            while (count < max) {
                count++;
                ants++;
            }
        }
        tmp = tmp->next;
    }
    return ants;
}