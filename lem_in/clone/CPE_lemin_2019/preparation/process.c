/*
** EPITECH PROJECT, 2020
** lem_in
** File description:
** process.c
*/

#include "../include/all_includes.h"

int my_array_len(void **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return (i);
}

room_stack_t *make_new_room(room_stack_t *new)
{
    new->next = NULL;
    new->room = malloc(sizeof(room_t));
    new->room->moves = INT_MAX;
    new->room->visited = FALSE;
    new->room->backtrack = NULL;
    new->room->way_len = 0;
    new->room->ways = NULL;
    return new;
}

int get_rooms(char **room_arguments, object *project, char *prev_str)
{
    room_stack_t *new = malloc(sizeof(room_stack_t));

    if (project->rooms->start) project->rooms->last->next = new;
    else project->rooms->start = new;
    new = make_new_room(new);
    new->prev = project->rooms->last;
    project->rooms->last = new;
    new->room->name = my_strdup(room_arguments[0]);
    if (my_str_isnum(room_arguments[1]) && my_getnbr(room_arguments[1]) >= 0)
        new->room->x = my_getnbr(room_arguments[1]);
    else return (ERR);
    if (my_str_isnum(room_arguments[2]) && my_getnbr(room_arguments[2]) >= 0)
        new->room->y = my_getnbr(room_arguments[2]);
    else return (ERR);
    if (my_strcmp(prev_str, "##start") == 0) project->start = new->room;
    if (my_strcmp(prev_str, "##end") == 0) project->end = new->room;
    project->len++;
    return (SUCCESS);
}

void free_arr(char **array)
{
    for (int i = 0; array[i] != NULL; i += 1)
        free(array[i]);
    free(array);
}

int prepare_object(object *project, head_t *stack, head_t *tunnel)
{
    char **tmp = NULL;
    if (stack->start && my_str_isnum(stack->start->str))
        project->ants = my_getnbr(stack->start->str);
    else return (ERR);
    for (stack_t *el = stack->start->next; el; el = el->next) {
        if (my_strcmp(el->str, "##start") && my_strcmp(el->str, "##end")) {
            tmp = my_str_to_word_array2(el->str, " ");
            if (my_array_len((void **) tmp) == 3) {
                if (get_rooms(tmp, project, el->prev->str) == ERR) return (ERR);
            } else {
                free_arr(tmp);
                tmp = my_str_to_word_array2(el->str, "-");
                if (my_array_len((void **) tmp) == 2) {
                    if (get_tunnels(tmp, project) == ERR ||
                        my_push(el->str, tunnel) == ERR) return (ERR);
                } else return (ERR);
            }
            free_arr(tmp);
        }
    }
    return (SUCCESS);
}