/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** struct
*/

#include <stdarg.h>
#include "my.h"

typedef struct my_para_t
{
    int place;
    int max;
    char pre;
    char plus;
    char plus2;
} my_params;

typedef struct my_preflagfunctions_t
{
    void (*f)(int, char, int);
    char flag;
} my_pre_functions;

typedef struct my_prints_t
{
    int (*f)(va_list, char *, my_params);
    char flag;
} my_prints;

typedef struct my_preflags_t
{
    my_params (*f)(char *, my_params);
    char flag;
} my_preflags;

void my_putoctal(int c);

int my_count_digits(int nb);

char *my_delete_zeros2(char *str);

int my_getnbr2(char const *str, int i);

void my_putoctal(int c);

void redirect_all_std(void);

int my_printf(char *, ...);

int va_put_pointer(va_list, char *, my_params);

int va_putchar(va_list, char *, my_params);

int va_putstr(va_list, char *, my_params);

int va_putstr2(va_list, char *, my_params);

int va_put_nbr(va_list, char *, my_params);

int count_digits(unsigned int);

int va_put_octal(va_list, char *, my_params);

int va_put_hexa2(va_list my_list, char *, my_params);

int va_put_hexa1(va_list my_list, char *, my_params);

int va_put_bin(va_list, char *, my_params);

int va_putpercent(va_list, char *, my_params);

int va_put_u_nbr(va_list my_list, char *, my_params);

my_preflags *my_get_preflags2(my_preflags *structure);

my_params va_format_hashtack(char *str, my_params params);

my_preflags *my_get_preflags(void);

my_prints *get_my_prints(void);

my_prints *get_my_prints2(my_prints *);

void modifyer_call(my_params params, int len, char flag, char *str);

my_params va_format_spaces(char *str, my_params params);

my_params va_format_plus(char *str, my_params params);

my_params va_format_number(char *str, my_params params);

my_params va_format_zero(char *str, my_params params);

my_params va_format_minus(char *str, my_params params);

my_preflags *my_get_preflags(void);

void my_print_zeros(int max, char flag, int call);

my_pre_functions *my_get_preflags_second();

void my_modify(my_params params, int len, char flag, int call);

void small_do_function(int nbr, char *string, my_params params, int i);