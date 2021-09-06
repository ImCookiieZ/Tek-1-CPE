/*
** EPITECH PROJECT, 2020
** solver
** File description:
** stacks.c
*/

#include "../include/all_includes.h"

coord_t *prepare_co(void)
{
    coord_t *start = NULL;

    start = malloc(sizeof(coord_t));
    if (start == NULL)
        my_error_exit("malloc co failed\n");
    start->x = 0;
    start->y = 0;
    start->prev = NULL;
    start->len = 0;
    return (start);
}

head_t *prepare_stack(void)
{
    head_t *stack = NULL;

    stack = malloc(sizeof(head_t));
    if (stack == NULL)
        my_error_exit("stack malloc failed\n");
    stack->start = NULL;
    stack->last = NULL;
    return (stack);
}

coord_t *my_pop(head_t *stack)
{
    coord_t *ret = malloc(sizeof(coord_t));
    stack_t *tmp = stack->start;

    if (ret == NULL)
        my_error_exit("pop not possible, malloc failed\n");
    ret->x = stack->start->x;
    ret->y = stack->start->y;
    ret->len = stack->start->len;
    ret->prev = stack->start->el_prev;
    stack->start = stack->start->next;
    if (stack->start == NULL)
        stack->last = NULL;
    free(tmp);
    return (ret);
}

void my_push(coord_t *coord, head_t *stack)
{
    stack_t *el = malloc(sizeof(stack_t));

    if (el == NULL)
        my_error_exit("push failed because of malloc\n");
    el->x = coord->x;
    el->y = coord->y;
    el->prev = stack->last;
    el->next = NULL;
    el->len = coord->len + 1;
    el->el_prev = coord->prev;
    if (stack->start == NULL)
        stack->start = el;
    else
        stack->last->next = el;
    stack->last = el;
}