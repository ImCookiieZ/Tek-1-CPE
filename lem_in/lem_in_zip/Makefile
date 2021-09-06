##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## for my_ls
##

SRC_LIB		=lib/my/concat_params.c \
		lib/my/my_strcat_char.c \
		lib/my/my_compute_power_rec.c \
		lib/my/my_strcmp.c \
		lib/my/my_compute_square_root.c \
		lib/my/my_strcpy.c \
		lib/my/my_delete_zeros.c \
		lib/my/my_strdup.c \
		lib/my/my_find_prime_sup.c \
		lib/my/my_getnbr.c \
		lib/my/my_isneg.c \
		lib/my/my_str_isnum.c \
		lib/my/my_is_prime.c \
		lib/my/my_str_isprintable.c \
		lib/my/my_putchar.c \
		lib/my/my_put_nbr.c \
		lib/my/my_strlen.c \
		lib/my/my_putstr.c \
		lib/my/my_revstr.c \
		lib/my/my_strncat.c \
		lib/my/my_memset.c \
		lib/my/my_strncpy.c \
		lib/my/my_show_word_array.c \
		lib/my/my_strstr.c \
		lib/my/my_swap.c \
		lib/my/my_sort_int_array.c \
		lib/my/my_str_to_word_array.c \
		lib/my/my_strcat.c \
		lib/my/flag_functions0.c \
		lib/my/flag_functions1.c \
		lib/my/flag_functions2.c \
		lib/my/formating1.c \
		lib/my/formating2.c \
		lib/my/formating.c \
		lib/my/my_declare_structure.c \
		lib/my/my_getnbr2.c \
		lib/my/my_printf.c \
		lib/my/do_other_things.c \
		lib/my/new_word_array.c

SRC		= $(SRC_LIB) \
		preparation/main.c \
		preparation/delete_comments.c \
		preparation/error.c \
		preparation/stacks.c \
		preparation/process.c \
		src/alg.c \
		src/len.c \
		src/print_alg.c

OBJ		=	$(SRC:.c=.o)

NAME		=	lem_in

CFLAGS = -I include/

CFLAGS += -W -Wall -Wextra -Wno-unused-parameter -Werror

CC = gcc -g

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm $(OBJ) $(OBJ_TEST) $(OBJ_MAIN)

fclean: clean
	rm $(NAME) $(MAIN) $(TEST)

re:	fclean all

.PHONY: all clean fclean re