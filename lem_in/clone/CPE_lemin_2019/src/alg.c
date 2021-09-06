/*
** EPITECH PROJECT, 2020
** lem_in
** File description:
** alg.c
*/

#include "../include/all_includes.h"

int my_push_alg(room_t *room, alg_head_t *stack, room_t *backtrack, int len)
{
    alg_stack_t *new = malloc(sizeof(alg_stack_t));

    if (room == NULL) {
        free(new);
        return (ERR);
    }
    if (new == NULL) return (ERR);
    if (stack->start == NULL) {
        stack->start = new;
        new->prev = NULL;
    } else {
        stack->end->next = new;
        new->prev = stack->end;
    }
    new->cur = room;
    new->cur->moves = len + 1;
    new->cur->backtrack = backtrack;
    new->next = NULL;
    stack->end = new;
    return (SUCCESS);
}

room_t *my_pop_alg(alg_head_t *stack)
{
    room_t *ret = NULL;
    alg_stack_t *tmp = stack->end;

    if (stack->end)
        ret = stack->end->cur;
    else
        return (ERROR_PTR);
    stack->end = stack->end->prev;
    if (stack->end == NULL)
        stack->start = NULL;
    free(tmp);
    return (ret);
}

void start(const object *my_struct, room_t *cur, alg_head_t *stack)
{
    while ((*stack).start) {
        cur = my_pop_alg(stack);
        for (int i = 0; cur->ways && cur->ways[i]; i++) {
            if ((cur->ways && cur->ways[i]->room != cur &&
            cur->ways[i]->room->moves > cur->moves) &&
            (cur->ways[i]->room->visited == FALSE || ((cur->ways[i]->room ==
            my_struct->end) && cur != my_struct->start))) {
                my_push_alg(cur->ways[i]->room, stack, cur, cur->moves);
            }
        }
    }
}