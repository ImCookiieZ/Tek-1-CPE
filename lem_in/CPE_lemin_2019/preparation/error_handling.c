/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int check_first_line(char *input)
{
    if (my_str_isnum(input))
        if (my_getnbr(input) > 0 && my_getnbr(input) < INT_MAX)
            return (0);
    return (8);
}

int check_tunnels(char *input, names_t *names, int values[5])
{
    char **array = NULL;
    int ret = 0;

    if (values[0] != 1 || values[1] != 1) return (1);
    array = my_str_to_word_array2(input, "-");
    if (my_arraylen(array) == 2) {
        ret = find_name(array[0], names);
        if (ret == 3)
            ret = find_name(array[1], names);
        return (ret);
    } else
        return (9);
}

int check_input(char *input, int values[5])
{
    int ret = 0;
    char **array = NULL;
    static names_t *head = NULL;

    array = my_str_to_word_array2(input, " ");
    for (int i = 0; array[i] != NULL; i += 1)
        if (array[i][0] == '#') array[i] = NULL;
    if (my_arraylen(array) == 3) {
        if (!my_str_isnum(array[1]) || !my_str_isnum(array[2])) ret = 1;
        else {
            head = add_name(head, array[0]);
            ret = 2;
        }
    }
    else if (my_arraylen(array) == 1) ret = check_tunnels(input, head, values);
    else ret = 1;
    for (int i = 0; array[i]; i += 1) free(array[i]);
    free(array);
    if (!ret && name_twice(head)) ret = 1;
    return (ret);
}

int final_check(int values[5])
{
    if (values[0] != 1 || values[1] != 1)
        return (1);
    return (0);
}

int is_valid(char *input, int last)
{
    int input_ret = 0;
    static int values[5] = {0, 0, 0, 0, 0};

    if (last) return (final_check(values));
    if (input == NULL || my_strlen(input) == 0) return (1);
    if (!my_strcmp(input, "##start")) {
        if (values[0] == 1) return (1);
        values[0] += 1;
        return (0);
    }
    if (!my_strcmp(input, "##end")) {
        if (values[1] == 1) return (1);
        values[1] += 1;
        return (0);
    }
    if (input[0] == '#') return (0);
    input_ret = check_input(input, values);
    if (input_ret == 2) values[2]++;
    if (input_ret == 3) values[3]++;
    if (input_ret == 1) return (1);
    return (0);
}