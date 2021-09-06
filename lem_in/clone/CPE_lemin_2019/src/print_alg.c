/*
** EPITECH PROJECT, 2019
** print_alg.c
** File description:
** for lem_in
*/

#include "../include/all_includes.h"

void make_second_clean(possible_ways_head_t *ways, head_ant_nbr_t *head)
{
    ant_nbr_t *tmp = NULL;
    possible_ways_stack_t *tmp2 = NULL;
    way_t *tmp_room = NULL;

    for (ant_nbr_t *ant_el = head->start; ant_el; ant_el = tmp) {
        tmp = ant_el->next;
        free(ant_el);
    }
    for (possible_ways_stack_t *el2 = ways->start; el2; el2 = tmp2) {
        tmp2 = el2->next;
        for (way_t *room = el2->cur->way_start; room; room = tmp_room) {
            tmp_room = room->next;
            free(room);
        }
        free(el2->cur);
        free(el2);
    }
}

void in_loop(ant_nbr_t *ant_el)
{
    ant_el->way = ant_el->way->prev;
    my_printf("P%d-", ant_el->ant_name);
    my_printf("%s", ant_el->way->room->name);
    if (ant_el->next != NULL)
        my_printf(" ");
}

void print_alg(possible_ways_head_t *ways, object *my_struct)
{
    head_ant_nbr_t head;
    possible_ways_stack_t *el;
    int left_ants = my_struct->ants;
    int min_ants = 0;
    head.start = NULL;
    head.last = NULL;
    ant_nbr_t *tmp = NULL;

    my_printf("#moves\n");
    while (min_ants < my_struct->ants) {
        for (el = ways->start; el; el = el->next)
            head = pre_push_ant(&head, el, &left_ants);
        if (head.start == NULL) return;
        pop_ant(my_struct, tmp, &head, &min_ants);
        my_printf("\n");
    }
    make_second_clean(ways, &head);
}