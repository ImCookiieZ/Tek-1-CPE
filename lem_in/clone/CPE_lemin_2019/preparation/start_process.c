/*
** EPITECH PROJECT, 2019
** Marcel Taubert - > start_process.c
** File description:
** lksdjf
*/

#include "../include/all_includes.h"

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
