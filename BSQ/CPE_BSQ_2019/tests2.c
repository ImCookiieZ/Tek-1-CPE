/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** TODO: add description
*/

/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** TODO: add description
*/


#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "include/my.h"
#include "include/tmp.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);
void my_testing(char *path);

Test(bsq, intermediate_map_one_empty_line1, .init = redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_one_empty_line";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_one_empty_line");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, intermediate_map_187_187_with_ob1stacles_75pc, .init =
    redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_187_187_with_obstacles_75pc";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_187_187_with_obstacles_75pc");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, intermediate_map_10001_1000, .init = redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_1000_1000";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_1000_1000");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, intermediate_map_34_1317_with_obstacles_50pc, .init =
    redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_34_137_with_obstacles_50pc";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_34_137_with_obstacles_50pc");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, intermediate_map_100_1010, .init = redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_100_100";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_100_100");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, intermediate_map_one_col1umn_with_obstacles_75pc, .init =
    redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_one_column_with_obstacles_75pc";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_one_column_with_obstacles_75pc");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, intermediate_map_187_187_1empty , .init = redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_187_187_empty";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_187_187_empty");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, intermediate_map_5000_50001, .init = redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_5000_5000";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_5000_5000");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, intermediate_map_10000_100010, .init = redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_10000_10000";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_10000_10000");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, intermediate_map_one_column_1with_obstacles_50pc, .init =
    redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_one_column_with_obstacles_50pc";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_one_column_with_obstacles_50pc");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, intermediate_map_97_21_filled1, .init = redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_97_21_filled";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_97_21_filled");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, intermediate_map_one_filled_bo1x, .init = redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_one_filled_box";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_one_filled_box");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, intermediate_map_empty_corner1s, .init = redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_empty_corners";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_empty_corners");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}

Test(bsq, interm1ediate_map_filled_corners, .init = redirect_all_std)
{
char *path;
struct stat buf;
int size = 0;
char *buffer;
int fd = 0;
int fd_size = 0;

path = "../mouli_maps_solved/intermediate_map_filled_corners";
stat(path, &buf);
size = buf.st_size;

buffer = malloc(sizeof(char) * (size + 1));
buffer[size] = '\0';
fd = open(path, O_RDONLY);
fd_size = read(fd, buffer, size);

my_testing("../mouli_maps/intermediate_map_filled_corners");
read(fd, buffer, size);
cr_assert_stdout_eq_str(buffer);
free(buffer);
}