/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int my_push_ants(head_ant_nbr_t *stack, possible_way_stack_t *way)
{
    static int nb = 1;
    ant_nbr_t *new = malloc(sizeof(ant_nbr_t));

    if (new == NULL)
        return (ERR);
    if (stack->start == NULL) {
        stack->start = new;
    } else {
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
    if (stack->start == NULL)
        stack->last = NULL;
    free(el);
}

void pop_ant(const object *my_struct, ant_nbr_t *tmp, head_ant_nbr_t *head,
    int *min_ants)
{
    for (ant_nbr_t *ant_el = (*head).start; ant_el;) {
        in_loop(ant_el);
        if (my_strcmp(ant_el->way->room->name, my_struct->end->name) == 0) {
            (*min_ants)++;
            tmp = ant_el->next;
            my_pop_ants(head, ant_el);
            ant_el = tmp;
        } else
            ant_el = ant_el->next;
    }
}

void push_ant(const possible_ways_stack_t *el, head_ant_nbr_t *head,
    int *left_ants)
{
    my_push_ants(head, el->cur);
    (*left_ants)--;
}

head_ant_nbr_t pre_push_ant(head_ant_nbr_t *head,
    const possible_ways_stack_t *el, int *left_ants)
{
    if ((*left_ants) > el->cur->max_ants) push_ant(el, head, left_ants);
    return (*head);
}