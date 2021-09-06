/*
** EPITECH PROJECT, 2020
** add_project_name
** File description:
** main.c
*/

#include "../include/all_includes.h"

head_t *create_stack(void)
{
    head_t *stack = malloc(sizeof(head_t));

    if (!(stack))
        my_error_exit("malloc failed in first allocation for function\n");
    stack->start = NULL;
    stack->last = NULL;
    return (stack);
}

coord_t *create_co(void)
{
    coord_t *co = malloc(sizeof(coord_t));

    co->y = 0;
    co->x = 0;
    return (co);
}

void my_error(int ac, char **av)
{
    if (!(my_str_isnum(av[1]) && my_getnbr(av[1]) >= 1))
        exit(84);
    if (!(my_str_isnum(av[2]) && my_getnbr(av[2]) >= 1))
        exit(84);
}

int main(int ac, char **av)
{
    srand(time(NULL));
    if (ac < 3 || ac > 4)
        return (84);
    my_error(ac, av);
    if (ac == 4 && (my_strcmp(av[3], "[perfect]") == 0 || my_strcmp(av[3],
        "perfect") == 0))
        perfect_dfa(my_getnbr(av[1]), my_getnbr(av[2]), TRUE);
    else
        perfect_dfa(my_getnbr(av[1]), my_getnbr(av[2]), FALSE);
    return (0);
}