/*
** EPITECH PROJECT, 2019
** CPE_getnextline_bootstrap_2019
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

void my_str_cut(char **dest, char **src)
{
    int len = my_strlen(*src);
    char *tmp = malloc(sizeof(char) * (len + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    for (; *src[i] && *src[i] != '\n'; i++) {
        *dest[i] = *src[i];
    }
    *dest[i] = '\0';
    for (; *src[i]; i++, j++) {
        tmp[j] = *src[i];
    }
    for (; *src[k]; k++)
        src[k] = '\0';
    *src = my_str_edit(&(**src), tmp, 2);
}

char *get_next_line(int fd)
{
    int i = 0;
    int j = 0;
    int h = 0;
    char *buffer_read = malloc(sizeof(char) * (READ_SIZE + 2));
    char *buffer_ret = malloc(sizeof(char) * (READ_SIZE + 2));
    static char *tmp = NULL;
    static char *tmp_complete = NULL;
    int len_tmp = 0;
    int len_complete = 0;
    int counter = 1;
    static int ret = 1;

    if (ret == 0)
        return (NULL);
    if (!tmp) {
        tmp = malloc(sizeof(char) * READ_SIZE + 2);
        tmp_complete = malloc(sizeof(char) * READ_SIZE + 2);
        tmp[0] = 0;
        tmp_complete[0] = 0;
    }
    else {
        len_tmp = my_strlen(tmp);
        j = len_tmp;
        len_complete = my_strlen(tmp_complete);
    }
    buffer_read[READ_SIZE] = 0;
    while ((ret = (read(fd, buffer_read, (READ_SIZE)))) != 0 && ret != -1) {
        putchar('+');
        buffer_read[ret] = '\0';
        buffer_ret = malloc(sizeof(char) * (READ_SIZE * counter + j + 1));
        if (len_tmp != 0)
            buffer_ret = my_str_edit(buffer_ret, tmp, 3);
        free(tmp);
        tmp = malloc(sizeof(char) * (READ_SIZE * counter + j + 1));
        tmp_complete = malloc(sizeof(char) * (READ_SIZE * counter + j + 1));
        if (len_tmp == len_complete) {
            putchar('#');
            for (; buffer_read[i] != '\0' && buffer_read[i] !=
            '\n'; i++, j++) {
                buffer_ret[j] = buffer_read[i];
                buffer_ret[j + 1] = '\0';
            }
            printf(buffer_ret);
            fflush(stdout);
            if (buffer_read[i] == '\n') {
                i++;
                for (h = 0;
                    buffer_read[i] && buffer_read[i] != '\n'; h++, i++) {
                    tmp[h] = buffer_read[i];
                }
                tmp[h] = 0;
                tmp_complete = my_str_edit(tmp_complete, tmp, 2);
                for (h = h - 1; buffer_read[i + 1]; i++, h++)
                    tmp_complete[h] = buffer_read[i + 1];
                tmp_complete[h] = 0;
                printf("\ntmp: %s\ntmp_complete: %s\nBuffer_re: %s\n", tmp,
                    tmp_complete, buffer_ret);
                fflush(stdout);
                break;
            }
            i = 0;
            counter++;
            tmp = my_str_edit(tmp, buffer_ret, 3);
            free(buffer_ret);
        }
        else {
            buffer_ret = my_str_edit(buffer_ret, tmp, 3);
            my_str_cut(&tmp, &tmp_complete);
        }
    }
    if (ret == 0 && tmp[0] == 0)
        return (NULL);
    else if (ret == 0)
        return (tmp);
    return (buffer_ret);
}