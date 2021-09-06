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
    get_start_list(&list1, &list2, head_lists);
    int i = 0;
    my_putchar('\n');
    printf("list1: ");
    while (i < head_lists->len1){
        printf("%i", list1->nb);
        printf(" ");
            list1 = list1->next;
        i++;
    }
    i = 0;
    printf("\nlist2:");
    while (list2 && i < head_lists->len2){
        printf("%i", list2->nb);
        printf(" ");
        if (list2 != head_lists->last2)
            list2 = list2->next;
        else
            break;
        i++;
    }
    printf("\n");
    fflush(stdout);
}
