/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

names_t *add_name(names_t *head, char *input)
{
    names_t *tmp = head;

    if (head == NULL) {
        if ((head = malloc(sizeof(names_t))) == NULL)
            return (NULL);
        head->name = my_strdup(input);
        head->has_tunnel = 0;
        head->next = NULL;
        return (head);
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    if ((tmp->next = malloc(sizeof(names_t))) == NULL)
        return (NULL);
    tmp->next->name = my_strdup(input);
    tmp->next->next = NULL;
    tmp->has_tunnel = 0;
    return (head);
}

int name_twice(names_t *head)
{
    int counter_i = 0;
    int counter_j = 0;
    names_t *tmp = head;

    if (head == NULL)
        return (0);
    for (names_t *i = tmp; i != NULL; i = i->next, counter_i++) {
        for (names_t *j = tmp; j != NULL; j = j->next,
            counter_j++) {
            if (counter_i != counter_j && !my_strcmp(i->name, j->name))
                return (1);
        }
        counter_j = 0;
    }
    return (0);
}

int find_name(char *input, names_t *head)
{
    names_t *tmp = head;

    if (head == NULL)
        return (1);
    for (; tmp != NULL; tmp = tmp->next) {
        if (!my_strcmp(input, tmp->name)) {
            tmp->has_tunnel = 1;
            return (3);
        }
    }
    return (1);
}