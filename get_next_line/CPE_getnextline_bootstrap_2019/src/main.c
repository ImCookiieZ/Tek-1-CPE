/*
** EPITECH PROJECT, 2019
** CPE_getnextline_bootstrap_2019
** File description:
** TODO: add description
*/

#include <string.h>
#include <zconf.h>
#include "../include/CPE_getnextline_bootstrap_2019.h"

char *read_next_n_bytes(int fd, int n)
{
    char *buffer_read = malloc(sizeof(char) * READ_SIZE);
    int ret = 0;
    char *buffer_ret = NULL;
    static int i = 0;
    int j = 0;

    while ((ret = read(fd, buffer_read, 1)) != -1) {
        buffer_ret = malloc(sizeof(char) * strlen(buffer_read) + 1);
        while (buffer_read[i] != '\0' && buffer_read[i] != '\n') {
            buffer_ret[j] = buffer_read[i];
            i++;
            j++;
        }
    }
    fflush(stdout);
    return (buffer_ret);
}

int main(int ac, char **argv)
{
    char *s = read_next_n_bytes(0, 8);
    while (s) {
        my_putstr(s);
        my_putchar('\n');
        free(s);
        s = read_next_n_bytes(0, 8);
    }
    return (0);
}