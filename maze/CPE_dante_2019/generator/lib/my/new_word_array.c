/*
** EPITECH PROJECT, 2019
** nothing
** File description:
** nothing
*/

#include "../include/all_includes.h"

int is_alnum2(char const character, char const *seperator)
{
    for (int i = 0; seperator[i]; i++)
        if (character == seperator[i] || character == '\t')
            return (0);
    if (character == 0)
        return (0);
    return (1);
}

int counts_words2(char const *str, char *seperator)
{
    int counter = 0;
    int len = 0;

    len = my_strlen(str);
    for (int i = 0; i < len; i++) {
        while (is_alnum2(str[i], seperator) == 1)
            i++;
        if (i != 0 && is_alnum2(str[i - 1], seperator) == 1)
            counter++;
    }
    return (counter);
}

int counts_character2(char const *str, int toto, char *seperator)
{
    int counter = 0;

    for (int i = toto; is_alnum2(str[i], seperator) == 1; i++)
        counter++;
    return (counter);
}

char **my_str_to_word_array2(char const *str, char *seperator)
{
    int l = 0;
    int count_words = counts_words2(str, seperator);
    int string_length = 0;
    int c = 0;
    char **array = malloc(sizeof(char *) * (count_words + 2));

    for (int i = 0; l < count_words && str[i] != '\0'; i++) {
        if (str[i] != '\0' && is_alnum2(str[i], seperator) == 1) {
            string_length = counts_character2(str, i, seperator);
            array[l] = malloc(sizeof(char) * (string_length + 1));
            for (c = 0; c < string_length; c++) {
                array[l][c] = str[i];
                i++;
            }
            array[l][c] = 0;
            l++;
        }
    }
    array[l] = NULL;
    return (array);
}