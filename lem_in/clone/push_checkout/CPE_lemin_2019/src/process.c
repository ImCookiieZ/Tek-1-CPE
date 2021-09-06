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

int get_rooms(char **room_arguments, object *project, char *prev_str)
{
    room_stack_t *new = malloc(sizeof(room_stack_t));

    if (project->rooms->start) project->rooms->last->next = new;
    else project->rooms->start = new;
    new->prev = project->rooms->last;
    new->next = NULL;
    project->rooms->last = new;
    new->room = malloc(sizeof(room_t));
    new->room->way_len = 0;
    new->room->ways = NULL;
    if (my_str_isnum(room_arguments[0]) && my_getnbr(room_arguments[0]) >= 0)
        new->room->nb = my_getnbr(room_arguments[0]);
    else return (ERROR_INT);
    if (my_str_isnum(room_arguments[1]) && my_getnbr(room_arguments[1]) >= 0)
        new->room->x = my_getnbr(room_arguments[1]);
    else return (ERROR_INT);
    if (my_str_isnum(room_arguments[2]) && my_getnbr(room_arguments[2]) >= 0)
        new->room->y = my_getnbr(room_arguments[2]);
    else return (ERROR_INT);
    if (my_strcmp(prev_str, "##start") == 0) project->start = new->room;
    if (my_strcmp(prev_str, "##end") == 0) project->end = new->room;
    project->len++;
    return (SUCCESS);
}

int get_tunnels(char **tunnels, object *project)
{
    room_stack_t *el_room1 = NULL;
    room_stack_t *el_room2 = NULL;
    int room1 = my_getnbr(tunnels[0]);
    int room2 = my_getnbr(tunnels[1]);

    if (!(my_str_isnum(tunnels[0]) && my_str_isnum(tunnels[1])))
        return (ERROR_INT);
    if (!(room1 <= project->len && room1 >= 0 && room2 >= 0 && room2
    <= project->len))
        return (ERROR_INT);
    el_room1 = project->rooms->start;
    for (int i = 0; i < room1; i++) el_room1 = el_room1->next;
    if (el_room1->room->ways == NULL)
        el_room1->room->ways = malloc(sizeof(room_stack_t *) *
            (project->len + 1));
    el_room2 = project->rooms->start;
    for (int i = 0; i < room2; i++) el_room2 = el_room2->next;
    if (el_room2->room->ways == NULL)
        el_room2->room->ways = malloc(sizeof(room_stack_t *) *
            (project->len + 1));
    el_room1->room->ways[el_room1->room->way_len] = el_room2;
    el_room1->room->way_len++;
    el_room2->room->ways[el_room1->room->way_len] = el_room1;
    el_room2->room->way_len++;
    return (SUCCESS);
}

int prepare_object(object *project, head_t *stack, head_t *tunnel)
{
    char **tmp_array = NULL;

    if (my_str_isnum(stack->start->str))
        project->ants = my_getnbr(stack->start->str);
    else
        return (ERROR_INT);
    for (stack_t *el = stack->start->next; el; el = el->next) {
        if (my_strcmp(el->str, "##start") != 0 && my_strcmp(el->str, "##end")
        != 0) {
            tmp_array = my_str_to_word_array2(el->str, " ");
            if (my_array_len((void **) tmp_array) == 3) {
                if (get_rooms(tmp_array, project, el->prev->str) == ERROR_INT)
                    return (ERROR_INT);
            }
            else {
                for (int i = 0; tmp_array[i]; i++)
                    free(tmp_array[i]);
                free(tmp_array);
                tmp_array = my_str_to_word_array2(el->str, "-");
                if (my_array_len((void **) tmp_array) == 2) {
                    if (get_tunnels(tmp_array, project) == ERROR_INT ||
                    my_push(el->str, tunnel) == ERROR_INT)
                        return (ERROR_INT);
                }
                else
                    return (ERROR_INT);
            }
            for (int i = 0; tmp_array[i]; i++)
                free(tmp_array[i]);
            free(tmp_array);
        }
    }
    return (SUCCESS);
}

int start_process(head_t *stack)
{
    object game_struc = {0, malloc(sizeof(rooms_head_t)), NULL, NULL, 0};
    room_stack_t *tmp = NULL;
    stack_t *tmp_2 = NULL;
    head_t *tunnel = malloc(sizeof(head_t));

    tunnel->start = NULL;
    tunnel->last = NULL;
    if (!(game_struc.rooms))
        return (ERROR_INT);
    game_struc.rooms->last = NULL;
    game_struc.rooms->start = NULL;
    delete_comments(stack);
    delete_empty_lines(stack);
    if (prepare_object(&game_struc, stack, tunnel) == 84)
        return (ERROR_INT);
    print_end(&game_struc, tunnel);
    for (stack_t *el = tunnel->start; el; free(el->str), free(el), el = tmp_2){
        tmp_2 = el->next;
    }
    free(tunnel);
    for (room_stack_t *el = game_struc.rooms->start; el; free(el->room->ways),
        free(el->room), free(el), el = tmp)
        tmp = el->next;
    free(game_struc.rooms);
    return (SUCCESS);
}
