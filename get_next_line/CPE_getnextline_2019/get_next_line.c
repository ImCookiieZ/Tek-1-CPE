/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** TODO: add description
*/

#include "get_next_line.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_str_edit(char *dest, char const *src, int edit)
{
    unsigned i = 0;
    int len = 0;

    if (edit < 2)
        len = my_strlen(dest);
    if (edit % 2 == 0) {
        for (i = len; src[i]; i++) {
            dest[i] = src[i];
        }
        dest[i] = '\0';
    }
    else if (edit % 2 == 1) {
        for (i = len; src[i] && src[i] != '\n'; i++) {
            dest[i] = src[i];
        }
        dest[i] = '\0';
    }
    return (dest);
}

char *edit_tmps(char **buffer_ret, char *tmp)
{
    char *my_tmp = malloc(my_strlen(tmp));
    int i = 0;
    int j = 0;

    for (; tmp[i] && tmp[i] != '\n'; i++) {
        *buffer_ret[i] = tmp[i];
    }
    *buffer_ret[i] = '\0';
    if (*buffer_ret[0] == 0)
        *buffer_ret = NULL;
    for (i++; tmp[i]; i++)
        my_tmp[j] = tmp[i];
    my_tmp[j] = 0;
    return (my_tmp);
}

int copy_tmp(char *buffer_ret, char *left_readed)
{
    int i = 0;
    int j = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(left_readed) + 1));

    tmp = my_str_edit(tmp, left_readed, 2);
    for (; left_readed[i] && left_readed[i] != '\n'; i++)
        buffer_ret[i] = left_readed[i];
    buffer_ret[i] = 0;
    for (; left_readed[j]; j++)
        left_readed[j] = 0;
    if (tmp[i] == '\n') {
        for (j = 0, i++; tmp[i] != '\0'; i++, j++)
            left_readed[j] = tmp[i];
    }
    left_readed[j] = 0;
    free(tmp);
    if (left_readed[0] == 0)
        return (1);
    return (0);
}

char *get_bigger_ret(char *buffer_ret)
{
    int len_buf = my_strlen(buffer_ret);
    char *tmp = malloc(sizeof(char) * (len_buf + 1));

    tmp = my_str_edit(tmp, buffer_ret, 2);
    free(buffer_ret);
    buffer_ret = malloc(sizeof(char) * (len_buf + READ_SIZE * 2 + 1));
    buffer_ret = my_str_edit(buffer_ret, tmp, 2);
    free(tmp);
    return (buffer_ret);
}

char *get_next_line(int fd)
{
    static char *left_readed = NULL;
    char *tmp = NULL;
    char *buffer_ret = malloc(sizeof(char) * (READ_SIZE * 2 + 1));
    char *buffer_read = malloc(sizeof(char) * (READ_SIZE + 1));
    static int ret = 1;
    int counter = 0;
    int i = 0;
    int k = 0;
    int j = 0;
    int last = 0;
    int len_buf = 0;

    if (left_readed == NULL) {
        left_readed = malloc(sizeof(char) * (READ_SIZE * 50 + 1));
        left_readed[0] = 0;
    }
    if (ret == 0 && left_readed[0] == 0 || READ_SIZE <= 0) {
        free(buffer_ret);
        free(buffer_read);
        free(left_readed);
        return (NULL);
    }
    if (copy_tmp(buffer_ret, left_readed) == 0) {
        free(buffer_read);
        return (buffer_ret);
    }
    ret = read(fd, buffer_read, READ_SIZE);
    while (ret != 0 && ret != -1) {
        len_buf = my_strlen(buffer_ret);
        buffer_ret = get_bigger_ret(buffer_ret);
        for (i = 0, k = len_buf; i < ret &&
        buffer_read[i] != '\n';
        i++, k++)
            buffer_ret[k] = buffer_read[i];
        buffer_ret[k] = 0;
        if (i != READ_SIZE) {
            i++;
            for (j = 0; i < ret; i++, j++)
                left_readed[j] = buffer_read[i];
            left_readed[j] = 0;
            free(buffer_read);
            return (buffer_ret);
        }
        free(buffer_read);
        buffer_read = malloc(sizeof(char) * READ_SIZE + 1);
        ret = read(fd, buffer_read, READ_SIZE);
    }
    if (ret == -1 || (ret == 0 && left_readed[0] == 0) || READ_SIZE <= 0) {
        free(buffer_ret);
        free(buffer_read);
        free(left_readed);
        return (NULL);
    }
    free(buffer_read);
    return (buffer_ret);
}