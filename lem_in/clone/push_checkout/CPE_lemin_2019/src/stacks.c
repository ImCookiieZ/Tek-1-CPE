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
        return (ERROR_INT);
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
