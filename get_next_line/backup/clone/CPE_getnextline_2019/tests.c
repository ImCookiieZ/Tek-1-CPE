/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** TODO: add description
*/


#include "get_next_line.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
}

Test(get_line, first_line, .init=redirect_all_std)
{
    int fd = open("test", O_RDONLY);
    char *str = get_next_line(fd);

    /*printf(str);
    fflush(stdout);
    cr_assert_stdout_eq_str("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
*/
    str = get_next_line(fd);
/*    printf(str);
    fflush(stdout);
    cr_assert_stdout_eq_str("Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
*/
    str = get_next_line(fd);
/*    printf(str);
    fflush(stdout);
    cr_assert_stdout_eq_str("Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");
*/
    str = get_next_line(fd);
/*    printf(str);
    fflush(stdout);
    cr_assert_stdout_eq_str("Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.");

*/    str = get_next_line(fd);
    printf(str);
    fflush(stdout);
    cr_assert_stdout_eq_str("Excepteur sint occaecat cupidatat non proident, "
                            "sunt in culpa qui officia");
}