/*
** EPITECH PROJECT, 2020
** generator
** File description:
** stacks.c
*/

#include "../include/all_includes.h"

void my_push(coord_t *coord, head_t *stack)
{
    stack_t *el = malloc(sizeof(stack_t));

    if (el == NULL)
        my_error_exit("push failed because of malloc\n");
    el->x = coord->x;
    el->y = coord->y;
    el->next = NULL;
    el->prev = stack->last;
    if (stack->start == NULL)
        stack->start = el;
    else
        stack->last->next = el;
    stack->last = el;
}

coord_t *my_pop(head_t *stack)
{
    coord_t *ret = malloc(sizeof(coord_t));
    stack_t *tmp = stack->last;

    if (ret == NULL)
        my_error_exit("Malloc failed in pop ll: 72\n");
    ret->x = stack->last->x;
    ret->y = stack->last->y;
    stack->last = stack->last->prev;
    if (stack->last == NULL)
        stack->start = NULL;
    free(tmp);
    return (ret);
}