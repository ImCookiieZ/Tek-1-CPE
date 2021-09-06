/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "include/push_swap.h"

void end_prining(list_t *list1, list_t *list2, head_t *head_lists)
{
    //printf("\nend before\n");
    //bigin end
    //check
    printf("list1: ");
    while (list1){
        printf("%i", list1->nb);
        printf(" ");
        if (list1 != head_lists->last1)
            list1 = list1->next;
        else
            break;
    }
    printf("\nlist2: \n");
    while (list2){
        printf("%i", list2->nb);
        printf(" ");
        if (list2 != head_lists->last2)
            list2 = list2->next;
        else
            break;
    }
    printf("\n");
}
