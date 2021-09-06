/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "../include/push_swap.h"

void add_head_and_end1(list_t **list1, head_t **heads)
{
    for (*list1 = (*heads)->start1; *list1;) {
        (*heads)->last1 = *list1;
        if ((*list1)->next)
            *list1 = (*list1)->next;
        else {
            (*list1)->next = (*heads)->start1;
            *list1 = (*heads)->start1;
            (*list1)->before = (*heads)->last1;
            break;
        }
    }
}

void add_head_and_end2(list_t **list2, head_t **heads)
{
    for (*list2 = (*heads)->start2; *list2;) {
        (*heads)->last2 = *list2;
        if ((*list2)->next)
            *list2 = (*list2)->next;
        else {
            (*list2)->next = (*heads)->start2;
            *list2 = (*heads)->start2;
            (*list2)->before = (*heads)->last2;
            break;
        }
    }
}

list_t *my_get_list(int i, list_t *tmp, int arg_len, char **arg)
{
    list_t *element;
    if (i < arg_len) {
        element = malloc(sizeof(list_t));
        element->nb = my_getnbr(arg[i + 1]);
        element->before = tmp;
        tmp = element;
        element->next = my_get_list(i + 1, tmp, arg_len, arg);
    }
    else
        return (NULL);
    return (element);
}

int my_error_checker(int ac, char **av)
{
    int my_error = 0;

    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j] != 0; j++)
            if ((av[i][j] < '0' || av[i][j] > '9') && !(av[i][j] == '-' ||
            av[i][j] == '+')) {
                write(2, "Error: only numbers pls!\n", 25);
                return (84);
            }
    }
    return (my_error);
}

int main(int ac, char **av)
{
    int my_error = my_error_checker(ac, av);
    int ret = 0;
    if (my_error == 0)
        ret = run_function(ac, av);
    else
        return (84);
    return (ret);
}