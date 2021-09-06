/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** TODO: add description
*/

#include "get_next_line.h"

char *my_str_edit(char *dest, char const *src, int edit)
{
    unsigned i = 0;
    int len = 0;

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

int copy_tmp(char *buffer_ret, char *left_readed, int func)
{
    int i = 0;
    int j = 0;
    char *tmp = malloc(sizeof(char) * (50 * READ_SIZE + 1));

    if (func == 0) {
        for (; buffer_ret[i]; i++);
        return (i);
    }
    tmp = my_str_edit(tmp, left_readed, 2);
    for (; left_readed[i] && left_readed[i] != '\n'; i++)
        buffer_ret[i] = left_readed[i];
    buffer_ret[i] = 0;
    for (; left_readed[j]; left_readed[j] = 0, j++);
    if (tmp[i] == '\n')
        for (j = 0, i++; tmp[i] != '\0'; left_readed[j] = tmp[i], i++, j++);
    left_readed[j] = 0;
    free(tmp);
    if (left_readed[0] == 0)
        return (1);
    return (0);
}

char *get_bigger_ret(char *buffer_ret, int counter)
{
    int len_buf = counter * READ_SIZE;
    char *tmp = malloc(sizeof(char) * (len_buf + 1));

    tmp = my_str_edit(tmp, buffer_ret, 2);
    buffer_ret = malloc(sizeof(char) * (len_buf + READ_SIZE * 2 + 1));
    buffer_ret = my_str_edit(buffer_ret, tmp, 2);
    free(tmp);
    return (buffer_ret);
}

char *my_loop(vars_t vars, char *buffer_ret, char *buffer_read, char
*left_readed)
{
    for (; vars.ret != 0 && vars.ret != -1; vars.counter++) {
        vars.len_buf = copy_tmp(buffer_ret, NULL, 0);
        buffer_ret = get_bigger_ret(buffer_ret, vars.counter + 1);
        for (vars.i = 0, vars.k = vars.len_buf; vars.i < vars.ret &&
        buffer_read[vars.i] != '\n'; vars.i++, vars.k++)
            buffer_ret[vars.k] = buffer_read[vars.i];
        buffer_ret[vars.k] = 0;
        if (vars.i != vars.ret) {
            for (vars.j = 0, vars.i++; vars.i < vars.ret; vars.i++, vars.j++)
                left_readed[vars.j] = buffer_read[vars.i];
            left_readed[vars.j] = 0;
            return (buffer_ret);
        }
        free(buffer_read);
        buffer_read = malloc(sizeof(char) * (READ_SIZE + 1));
        vars.ret = read(vars.fd, buffer_read, READ_SIZE);
    }
    if (vars.ret == -1 || (vars.ret == 0 && left_readed[0] == 0 &&
    buffer_ret[0] == 0) || READ_SIZE <= 0)
        return (NULL);
    return (buffer_ret);
}

char *get_next_line(int fd)
{
    static char *left_readed = NULL;
    char *buffer_ret = malloc(sizeof(char) * (READ_SIZE * 2 + 1));
    char *buffer_read = malloc(sizeof(char) * (READ_SIZE + 1));
    static int ret = READ_SIZE;
    vars_t vars = {1, 0, 0, 0, 0, 0, NULL, ret, fd};

    if (left_readed == NULL)
        left_readed = malloc(sizeof(char) * (READ_SIZE * 50 + 1));
    if (buffer_ret == NULL || buffer_read == NULL || (((ret == 0  ||
    ret < READ_SIZE) && left_readed[0] == 0) || READ_SIZE <= 0)) return (NULL);
    if (copy_tmp(buffer_ret, left_readed, 1) == 0) {
        free(buffer_read);
        return (buffer_ret);
    } if (ret == READ_SIZE)
        ret = read(fd, buffer_read, READ_SIZE);
    else ret = 0;
    vars.ret = ret;
    buffer_ret = my_loop(vars, buffer_ret, buffer_read, left_readed);
    free(buffer_read);
    free(vars.tmp);
    return (buffer_ret);
}