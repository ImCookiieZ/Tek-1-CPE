/*
** EPITECH PROJECT, 2019
** main
** File description:
** bsq
*/

#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/tmp.h"

void bsq_put(char *buffer, int size)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *new = skip_first(buffer, size);
    char **array = formating(new);

    for (; new[j] != '\0'; j++, k++) {
        array[i][k] = new[j];
        if (new[j] == '\n') {
            array[i][k + 1] = '\0';
            i++;
            k = -1;
        }
    }
    array[i] = NULL;
    array = modify_array(array, i);
    free(new);
    for (int a = 0; array[a] != NULL; a++)
        free(array[a]);
    free(array);
}

int my_error_print(char *av)
{
    int len = my_strlen(av);

    write(2, "error: ", 6);
    write(2, av, len);
    if (errno ==  EACCES)
        write(2, ": Argument list too long\n", 26);
    if (errno == EINTR)
        write(2, ": Interrupted function call\n", 29);
    if (errno == EISDIR)
        write (2, ": Is a directory\n", 18);
    if (errno == ENOENT)
        write(2, ": No such file or directory\n", 29);
    return (84);
}

int my_open(char *file, int size)
{
    char *buffer = malloc(sizeof(char) * size + 1);
    int fd = 0;
    int fd_size = 0;
    int ret = 0;

    buffer[size] = '\0';
    for (int i = 0; i < size; i++)
        buffer[i] = '\0';
    fd = open(file, O_RDONLY);
    if (fd == -1)
        ret = my_error_print(file);
    else {
        fd_size = read(fd, buffer, size);
        bsq_put(buffer, size);
        free(buffer);
    }
    close(fd);
    return (ret);
}

/*int main(int ac, char **av)
{
    char *fd;
    struct stat buf;
    int size = 0;
    char *buffer;
    int ret = 0;

    if (ac < 2) {
        write(2, "Error: wrong number of arguments\n", 33);
        return (84);
    }
    else
        for (int i = 1; i < ac; i++) {
            fd = av[i];
            stat(fd, &buf);
            size = buf.st_size;
            ret = my_open(av[i], size);
            if (ret == 84)
                return (ret);
        }
    return (ret);
}*/