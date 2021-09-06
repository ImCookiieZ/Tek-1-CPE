/*
** EPITECH PROJECT, 2020
** lem_in
** File description:
** stacks.c
*/

#include "../include/all_includes.h"

int my_push(char *str, head_t *stack)
{
    stack_t *new = malloc(sizeof(stack_t));

    if (new == NULL)
        return (ERR);
    if (stack->start == NULL) {
        stack->start = new;
        new->nb = 0;
        new->prev = NULL;
    }
    else {
        new->nb = stack->last->nb + 1;
        stack->last->next = new;
        new->prev = stack->last;
    }
    new->str = my_strdup(str);
    new->next = NULL;
    stack->last = new;
    return (SUCCESS);
}

char *my_pop(head_t *stack)
{
    char *ret = NULL;
    stack_t *tmp = stack->last;

    if (stack->last)
        ret = my_strdup(stack->last->str);
    else
        return (ERROR_PTR);
    free(stack->last->str);
    stack->last = stack->last->prev;
    if (stack->last == NULL)
        stack->start = NULL;
    free(tmp);
    return (ret);
}

int my_push_room(room_t *room, possible_way_stack_t *stack)
{
    way_t *new = malloc(sizeof(way_t));

    if (new == NULL)
        return (ERR);
    if (stack->way_start == NULL) {
        stack->way_start = new;
        new->len_until_now = 0;
        new->prev = NULL;
        stack->active = TRUE;
        stack->shortest = FALSE;
    } else {
        new->len_until_now = stack->way_end->len_until_now + 1;
        stack->way_end->next = new;
        new->prev = stack->way_end;
    }
    stack->len++;
    new->room = room;
    new->next = NULL;
    stack->way_end = new;
    return (SUCCESS);
}

int my_push_way(possible_way_stack_t *way, possible_ways_head_t *stack)
{
    possible_ways_stack_t *new = malloc(sizeof(possible_ways_stack_t));

    if (new == NULL)
        return (ERR);
    if (stack->start == NULL) {
        stack->start = new;
        new->prev = NULL;
    } else {
        stack->end->next = new;
        new->prev = stack->end;
    }
    new->cur = way;
    new->next = NULL;
    stack->end = new;
    return (SUCCESS);
}
