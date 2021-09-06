/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

alg_head_t init_stack_way(possible_way_stack_t *way, alg_head_t *stack)
{
    way->way_start = NULL;
    way->way_end = NULL;
    way->len = 0;
    (*stack).start = NULL;
    (*stack).end = NULL;
    return (*stack);
}

void my_free_way(possible_way_stack_t *way, way_t *tmp_room)
{
    for (way_t *room = way->way_start; room; room = tmp_room) {
        tmp_room = room->next;
        free(room);
    }
    free(way);
}

possible_way_stack_t *find_shortest_way(object *my_struct)
{
    possible_way_stack_t *way = malloc(sizeof(possible_way_stack_t));
    room_t *cur = NULL;
    alg_head_t stack;
    way_t *tmp_room = NULL;

    stack = init_stack_way(way, &stack);
    my_push_alg(my_struct->start, &stack, NULL, 0);
    start(my_struct, cur, &stack);
    for (room_t *el = my_struct->end; 1; cur->backtrack = NULL) {
        cur = el;
        if (!(el)) {
            my_free_way(way, tmp_room);
            return (NULL);
        }
        el->visited = TRUE;
        my_push_room(el, way);
        if (el == my_struct->start) break;
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