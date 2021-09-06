/*
** EPITECH PROJECT, 2019
** CPE_getnextline_bootstrap_2019
** File description:
** TODO: add description
*/

#include <string.h>
#include <zconf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef CPE_GETNEXTLINE_BOOTSTRAP_2019_CPE_GET_NEXTLINE_BOOTSTRAP_2019_H
#define CPE_GETNEXTLINE_BOOTSTRAP_2019_CPE_GET_NEXTLINE_BOOTSTRAP_2019_H
#ifndef READ_SIZE
# define READ_SIZE 128
#endif /* !READ_SIZE */
char *get_next_line(int);
typedef struct vars_st{
    int counter;
    int i;
    int k;
    int j;
    int last;
    int len_buf;
    char *tmp;
    int ret;
    int fd;
}vars_t;
#endif //CPE_GETNEXTLINE_BOOTSTRAP_2019_CPE_GET_NEXTLINE_BOOTSTRAP_2019_H
