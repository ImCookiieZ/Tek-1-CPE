/*
** EPITECH PROJECT, 2019
** Marcel Taubert - > get_tunnel.c
** File description:
** ldskfj
*/

#include "../include/all_includes.h"

room_stack_t *room_one(const object *project, room_stack_t *el_room1,
        const char *room1)
{
    while (my_strcmp(el_room1->room->name, room1) != 0) el_room1 =
            el_room1->next;
    if (el_room1->room->ways == NULL)
        el_room1->room->ways = malloc(sizeof(room_stack_t *) *
                (project->len + 1));
    return el_room1;
}

void check_bool(const room_stack_t *el_room1, room_stack_t *el_room2, int bool)
{
    if (bool == FALSE) {
        el_room1->room->ways[el_room1->room->way_len] = el_room2;
        el_room1->room->way_len++;
        el_room1->room->ways[el_room1->room->way_len] = NULL;
    }
}

void check_bool_two(room_stack_t *el_room1, const room_stack_t *el_room2,
        int bool)
{
    bool = FALSE;
    for (int i = 0; i < el_room2->room->way_len; i++) {
        if (el_room1->room->name == el_room2->room->ways[i]->room->name)
            bool = TRUE;
    }
    if (bool == FALSE) {
        el_room2->room->ways[el_room2->room->way_len] = el_room1;
        el_room2->room->way_len++;
        el_room2->room->ways[el_room2->room->way_len] = NULL;
    }
}

room_stack_t *room_two(const object *project, room_stack_t *el_room2,
        const char *room2)
{
    while (my_strcmp(el_room2->room->name, room2) != 0)
        el_room2 = el_room2->next;
    if (el_room2->room->ways == NULL)
        el_room2->room->ways = malloc(sizeof(room_stack_t *) *
                (project->len + 1));
    return el_room2;
}

int get_tunnels(char **tunnels, object *project)
{
    room_stack_t *el_room1 = NULL;
    room_stack_t *el_room2 = NULL;
    char *room1 = my_strdup(tunnels[0]);
    char *room2 = my_strdup(tunnels[1]);
    int bool = FALSE;

    el_room1 = project->rooms->start;
    el_room1 = room_one(project, el_room1, room1);
    el_room2 = project->rooms->start;
    el_room2 = room_two(project, el_room2, room2);
    for (int i = 0; i < el_room1->room->way_len; i++) {
        if (el_room2->room->name == el_room1->room->ways[i]->room->name)
            bool = TRUE;
    }
    check_bool(el_room1, el_room2, bool);
    check_bool_two(el_room1, el_room2, bool);
    free(room1);
    free(room2);
    return (SUCCESS);
}