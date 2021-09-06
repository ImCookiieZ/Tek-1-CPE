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

    if (new == NULL)
        return (ERROR_INT);
    if (stack->start == NULL) {
        stack->start = new;
        new->prev = NULL;
    }
    else {
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

possible_way_stack_t *find_shortest_way(object *my_struct)
{
    possible_way_stack_t *way = malloc(sizeof(possible_way_stack_t));
    room_t *cur = NULL;
    alg_head_t stack;
    way_t *tmp_room = NULL;

    way->way_start = NULL;
    way->way_end = NULL;
    way->len = 0;
    stack.start = NULL;
    stack.end = NULL;
    my_push_alg(my_struct->start, &stack, NULL, 0);
    while (stack.start) {
        cur = my_pop_alg(&stack);
        for (int i = 0; cur->ways && cur->ways[i]; i++) {
            if ((cur->ways && cur->ways[i]->room != cur &&
            cur->ways[i]->room->visited ==
            FALSE && cur->ways[i]->room->moves > cur->moves) ||
            cur->ways[i]->room == my_struct->end) {
                my_push_alg(cur->ways[i]->room, &stack, cur, cur->moves);
            }
        }
    }
    for (room_t *el = my_struct->end; 1;
    cur->backtrack = NULL) {
        cur = el;
        if (!(el)) {
            for (way_t *room = way->way_start; room; room = tmp_room) {
                tmp_room = room->next;
                free(room);
            }
            free(way);
            return (NULL);
        }
        el->visited = TRUE;
        my_push_room(el, way);
        if (el == my_struct->start)
            break;
        el = el->backtrack;
    }
    return (way);
}

possible_ways_head_t get_ways(object *my_struct)
{
    possible_way_stack_t *way_cur = NULL;
    possible_ways_head_t ways;

    ways.start = NULL;
    ways.end = NULL;

    while (1) {
        way_cur = find_shortest_way(my_struct);
        if (way_cur == NULL)
            break;
        my_push_way(way_cur, &ways);
        way_cur->max_ants = get_max_value(&ways, way_cur->len);
    }
    return (ways);
}

//todo: use marcels alg to solve
