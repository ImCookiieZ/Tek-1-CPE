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

char *edit_tmps(char **buffer_ret, char *tmp)
{
    char *my_tmp = malloc(my_strlen(tmp));
    int i = 0;
    int j = 0;

    printf("tmo: %s", tmp);
    fflush(stdout);
    for (; tmp[i] && tmp[i] != '\n'; i++) {
        *buffer_ret[i] = tmp[i];
        write(1, "1", 1);
    }
    write(1, "1", 1);
    *buffer_ret[i] = '\0';
    write(1, "1", 1);
    if (*buffer_ret[0] == 0)
        *buffer_ret = NULL;
    write(1, "1", 1);
    for (i++; tmp[i]; i++)
        my_tmp[j] = tmp[i];
    my_tmp[j] = 0;
    return (my_tmp);
}

char *get_next_line(int fd)
{
    printf("readsize: %i\n", READ_SIZE);
    int i = 0;
    int h = 0;
    char *buffer_read = malloc(sizeof(char) * (READ_SIZE + 2));
    char *buffer_ret = malloc(sizeof(char) * (READ_SIZE + 2));
    static char *tmp = NULL;
    int len_tmp = 0;
    int counter = 1;
    static int ret = 1;

    printf("lol\n");
    if (ret == 0 && !tmp [0] || READ_SIZE < 0)
        return (NULL);
    printf("lol2\n");
    printf("lol3\n");
    if (!tmp) {
        tmp = malloc(sizeof(char) * READ_SIZE + 2);
        tmp[0] = 0;
    }
    else {
        len_tmp = my_strlen(tmp);
    }
    buffer_read[READ_SIZE] = 0;
    while ((ret = (read(fd, buffer_read, (READ_SIZE)))) != 0 && ret != -1) {
        buffer_read[ret] = '\0';
        buffer_ret = malloc(sizeof(char) * (READ_SIZE * counter + len_tmp + 1));
        if (len_tmp != 0)
            buffer_ret = my_str_edit(buffer_ret, tmp, 3);
        free(tmp);
        tmp = malloc(sizeof(char) * (READ_SIZE * counter + len_tmp + 1));
            while (buffer_read[i] != '\0' && buffer_read[i] != '\n') {
                buffer_ret[len_tmp] = buffer_read[i];
                i++;
                len_tmp++;
            }
            buffer_ret[len_tmp] = '\0';
            if (buffer_read[i] == '\n') {
                i++;
                for (h = 0;
                    buffer_read[i] && buffer_read[i] != '\n'; h++, i++) {
                    tmp[h] = buffer_read[i];
                }
                tmp[h] = 0;
                return (buffer_ret);
            }
            i = 0;
            counter++;
            tmp = my_str_edit(tmp, buffer_ret, 2);
            free(buffer_ret);
    }

    tmp = edit_tmps(&buffer_ret, tmp);
    return (buffer_ret);
}