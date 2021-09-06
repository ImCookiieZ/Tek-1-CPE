/*
** EPITECH PROJECT, 2020
** lem_in
** File description:
** delete_comments.c
*/

#include "../include/all_includes.h"

void my_delete_node(stack_t *el, head_t *stack)
{
    free(el->str);
    if (stack->start == el) {
        stack->start = el->next;
    } else
        el->prev->next = el->next;
    if (stack->last == el) {
        stack->last = el->prev;
    } else
        el->next->prev = el->prev;
}

void delete_empty_lines(head_t *stack)
{
    stack_t *tmp = NULL;
    int delete = FALSE;

    for (stack_t *el = stack->start; el;  el = tmp) {
        tmp = el->next;
        if (my_strlen(el->str) == 0) {
            my_delete_node(el, stack);
            delete = TRUE;
        }
        if (delete == TRUE)
            free(el);
        delete = FALSE;
    }
}

void delete_comments(head_t *stack)
{
    stack_t *el = stack->start;
    int set_to_zero = FALSE;
    int hashtack_prev = FALSE;

    while (el) {
        for (int i = 0; el->str[i]; i++) {
            if (set_to_zero == TRUE)
                el->str[i] = '\0';
            if ((hashtack_prev == FALSE && el->str[i + 1] != '#') &&
            el->str[i] == '#') {
                el->str[i] = '\0';
                set_to_zero = TRUE;
            }
            hashtack_prev = FALSE;
            if (el->str[i] == '#')
                hashtack_prev = TRUE;
        }
        set_to_zero = FALSE;
        el = el->next;
    }
}