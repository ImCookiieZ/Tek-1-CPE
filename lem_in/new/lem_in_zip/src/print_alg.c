/*
** EPITECH PROJECT, 2019
** print_alg.c
** File description:
** for lem_in
*/

#include "../include/all_includes.h"

int my_push_ants(head_ant_nbr_t *stack, possible_way_stack_t *way)
{
    static int nb = 1;
    ant_nbr_t *new = malloc(sizeof(ant_nbr_t));

    if (new == NULL)
        return (ERROR_INT);
    if (stack->start == NULL) {
        stack->start = new;
    }
    else {
        stack->last->next = new;
        new->prev = stack->last;
    }
    new->ant_name = nb;
    new->way = way->way_end;
    nb++;
    new->next = NULL;
    stack->last = new;
    return (SUCCESS);
}

void my_pop_ants(head_ant_nbr_t *stack, ant_nbr_t *el)
{
    if (stack->start != el && el->prev)
        el->prev->next = el->next;
    if (stack->last != el && el->next)
        el->next->prev = el->prev;
    if (stack->start == el)
        stack->start = el->next;
    if (stack->last == el)
        stack->last = el->prev;
    if (stack->last == NULL)
        stack->start = NULL;
    free(el);
}

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

void print_alg(possible_ways_head_t *ways, object *my_struct)
{
    head_ant_nbr_t head;
    possible_ways_stack_t *el;
    int left_ants = my_struct->ants;
    int min_ants = 0;
    head.start = NULL;
    head.last = NULL;

    my_printf("#moves\n");
    while (min_ants < my_struct->ants)
    {
        for (el = ways->start; el; el = el->next) {
            if (left_ants > el->cur->max_ants) {
                my_push_ants(&head, el->cur);
                left_ants--;
            }
        }
        for (ant_nbr_t *ant_el = head.start; ant_el;) {
            ant_el->way = ant_el->way->prev;
            my_printf("P%d-%s", ant_el->ant_name, ant_el->way->room->name);
            if (ant_el->next != NULL)
                my_printf(" ");
            if (my_strcmp(ant_el->way->room->name, my_struct->end->name) == 0) {
                min_ants++;
                ant_el = ant_el->next;
                if (ant_el)
                my_pop_ants(&head, ant_el->prev);
            } else {
                ant_el = ant_el->next;
            }
        }
        my_printf("\n");
    }
    make_second_clean(ways, &head);
}