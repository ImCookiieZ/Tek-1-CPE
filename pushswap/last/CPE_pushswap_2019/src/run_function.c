/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "../include/push_swap.h"

void get_start_list(list_t **list1, list_t **list2, head_t *head_list)
{
    *list1 = head_list->start1;
    *list2 = head_list->start2;
}

int run_function(int ac, char **av)
{
    int i = 0;
    list_t *tmp = malloc(sizeof(list_t));
    list_t *list1 = my_get_list(i, tmp, ac - 1, av);
    list_t *list2 = my_get_list(i, tmp,  0, NULL);
    head_t *head_lists = malloc(sizeof(head_t));
    string_list_t *output = malloc(sizeof(string_list_t));

    head_lists->start1 = list1;
    head_lists->start2 = list2;
    add_head_and_end1(&list1, &head_lists);
    add_head_and_end2(&list1, &head_lists);
    get_start_list(&(list1), &(list2), head_lists);
    list1 = my_sort(list1, list2, head_lists);
    my_putchar('\n');
    return (0);
}