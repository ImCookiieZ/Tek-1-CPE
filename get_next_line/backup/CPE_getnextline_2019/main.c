/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** TODO: add description
*/

#include "get_next_line.h"

char *get_NULL()
{
    return NULL;
}
int main(int ac, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    char *s;

    if (fd != -1 && ac == 2) {
        s = get_next_line(fd);
        if (s == NULL)
            return 84;
        while (s) {
            printf("%s #\n", s);
            fflush(stdout);
            free(s);
            s = get_next_line(fd);
        }
    }
    else if(ac == 1) {
        s = get_next_line(0);
        while (s) {
            printf("%s #\n", s);
            free(s);
            s = get_next_line(0);
        }
    }
    else
        return (84);
    return (0);
}