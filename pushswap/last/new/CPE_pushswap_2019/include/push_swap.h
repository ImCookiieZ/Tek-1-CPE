/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** TODO: add description
*/

#include "my.h"

#ifndef CPE_PUSHSWAP_2019_STRUCT_LINK_LIST_H
#define CPE_PUSHSWAP_2019_STRUCT_LINK_LIST_H

typedef struct string_list {
    struct string_list_t *next;
    char string[2];
    int ac;
}string_list_t;

typedef struct heads {
    struct lists *start1;
    struct lists *last1;
    struct lists *start2;
    struct lists *last2;
}head_t;

typedef struct lists {
    int nb;
    struct lists *next;
    struct lists *before;
}list_t;

int run_function(int ac, char **av);

void sa(list_t **list_a, list_t **list_b, head_t **heads, int first);
void sb(list_t **list_a, list_t **list_b, head_t **heads, int first);
void sc(list_t **list_a, list_t **list_b, head_t **heads, int first);

void ra(list_t **list_a, list_t **list_b, head_t **heads, int first);
void rb(list_t **list_a, list_t **list_b, head_t **heads, int first);
void rr(list_t **list_a, list_t **list_b, head_t **heads, int first);

void rra(list_t **list_a, list_t **list_b, head_t **heads, int first);
void rrb(list_t **list_a, list_t **list_b, head_t **heads, int first);
void rrr(list_t **list_a, list_t **list_b, head_t **heads, int first);

void pa2(list_t **list_a, list_t **list_b, head_t **heads, int first);
void pa(list_t **list_a, list_t **list_b, head_t **heads, int first);
void pb(list_t **list_a, list_t **list_b, head_t **heads, int first);

void get_start_list(list_t **list1, list_t **list2, head_t *head_list);
void add_head_and_end1(list_t **list1, head_t **heads);
void add_head_and_end2(list_t **list1, head_t **heads);
list_t *my_get_list(int i, list_t *tmp, int arg_len, char **arg);

list_t *my_sort(list_t *list_a, list_t *list_b, head_t *);
int my_error_checker(int ac, char **av);
int main(int ac, char **av);
void end_prining(list_t *list1, list_t *list2, head_t *head_lists);
#endif //CPE_PUSHSWAP_2019_STRUCT_LINK_LIST_H
