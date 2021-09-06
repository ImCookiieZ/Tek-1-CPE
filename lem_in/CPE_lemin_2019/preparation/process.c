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
    if (my_strcmp(prev_str, "##end") == 0 && project->start != NULL)
        project->end = new->room;
    else if (my_strcmp(prev_str, "##end") == 0 && project->start == NULL)
        return (ERR);
    return (SUCCESS);
}

room_stack_t *room_one(const object *project, room_stack_t *el_room1, const
char *room1)
{
    while (my_strcmp(el_room1->room->name, room1) != 0) el_room1 =
        el_room1->next;
    if (el_room1->room->ways == NULL)
        el_room1->room->ways = malloc(sizeof(room_stack_t *) * (project->len
            + 1));
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

room_stack_t *room_two(const object *project, room_stack_t *el_room2, const
char *room2)
{
    while (my_strcmp(el_room2->room->name, room2) != 0)
        el_room2 = el_room2->next;
    if (el_room2->room->ways == NULL)
        el_room2->room->ways = malloc(sizeof(room_stack_t *) * (project->len
            + 1));
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

void free_arr(char **array)
{
    for (int i = 0; array[i] != NULL; i += 1)
        free(array[i]);
    free(array);
}

int prepare_object(object *project, head_t *stack, head_t *tunnel)
{
    char **tmp = NULL;
    if (stack->start && my_str_isnum(stack->start->str) >= 0)
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

object create_game_struc(object game_struc, head_t *stack)
{
    game_struc.rooms->last = NULL;
    game_struc.rooms->start = NULL;
    delete_comments(stack);
    delete_empty_lines(stack);

    return game_struc;
}

void print(object game_struc, head_t *tunnel)
{
    possible_ways_head_t ways;
    print_end(&game_struc, tunnel);
    ways = get_ways(&game_struc);
    print_alg(&ways, &game_struc);
}

int start_process(head_t *stack)
{
    object game_struc = {0, malloc(sizeof(rooms_head_t)), NULL, NULL, 0};
    room_stack_t *tmp = NULL;
    stack_t *tmp_2 = NULL;
    head_t *tunnel = malloc(sizeof(head_t));

    tunnel->start = NULL;
    tunnel->last = NULL;
    if (!(game_struc.rooms)) return (ERR);
    game_struc = create_game_struc(game_struc, stack);
    if (prepare_object(&game_struc, stack, tunnel) == 84) return (ERR);
    print(game_struc, tunnel);
    for (stack_t *el = tunnel->start; el; free(el->str), free(el), el = tmp_2)
        tmp_2 = el->next;
    free(tunnel);
    for (room_stack_t *el = game_struc.rooms->start; el; free(el->room->ways),
            free(el->room->name), free(el->room), free(el), el = tmp)
        tmp = el->next;
    free(game_struc.rooms);
    return (SUCCESS);
}