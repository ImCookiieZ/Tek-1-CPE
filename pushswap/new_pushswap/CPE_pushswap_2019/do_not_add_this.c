/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "include/push_swap.h"

void end_prining(list_t *list1, list_t *list2, head_t *head_lists)
{
    printf("\n");
    get_start_list(&(list1), &(list2), head_lists);
    my_putstr("end_printing:\n");
    printf("list1: ");
    int i = 0;
    while (list1 && i < 100) {
        printf("%i", list1->nb);
        printf(" ");
        if (list1 != head_lists->last1)
            list1 = list1->next;
        else
            break;
        i++;
    }
    i = 0;
    printf("\nlist2: ");
    while (head_lists->start2 && i < 10) {
        printf("%i", list2->nb);
        printf(" ");
        if (list2 != head_lists->last2)
            list2 = list2->next;
        else
            break;
        i++;
    }
    printf("\nfin\n");
}
