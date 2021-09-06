/*
** EPITECH PROJECT, 2020
** lem_in
** File description:
** startc.c
*/

#include "../include/all_includes.h"

int make_valgring_clean(head_t *stack)
{
    if (stack->start == NULL)
        return (84);
    for (char *str = my_pop(stack); str; str = my_pop(stack)) {
        free(str);
    }
    return (SUCCESS);
}

int print_end(object *project, head_t *tunnel)
{
    my_printf("#number_of_ants\n%d\n", project->ants);
    my_printf("#rooms\n");
    for (room_stack_t *el = project->rooms->start; el; el = el->next) {
        if (el->room == project->start)
            my_printf("##start\n");
        if (el->room == project->end)
            my_printf("##end\n");
        my_printf("%s %d %d\n", el->room->name, el->room->x, el->room->y);
    }
    my_printf("#tunnels\n");
    for (stack_t *el = tunnel->start; el; el = el->next) {
        my_printf("%s\n", el->str);
    }
    return (SUCCESS);
}

int end(char *line, head_t *stack)
{
    int ret;
    if (is_valid(NULL, 1)) ret = 84;
    free(line);
    ret = start_process(stack);
    if (make_valgring_clean(stack) == 84) ret = 84;
    free(stack);
    return ret;
}

int main(int ac, char **av)
{
    int is_first = 1;
    int ret = 0;
    char *line = NULL;
    int size = 0;
    size_t buff_size = 0;
    head_t *stack = malloc(sizeof(head_t));

    stack->start = NULL;
    stack->last = NULL;
    while ((size = getline(&line, &buff_size, stdin)) != -1 && ret == 0) {
        if (line[size - 1] == '\n') line[size - 1] = '\0';
        if (is_first) {
            if (line[0] == '#') continue;
            if (check_first_line(line)) break;
            is_first = 0;
        } else if (is_valid(line, 0)) break;
        ret = my_push(line, stack);
    }
    ret = end(line, stack);
    return (ret);
}