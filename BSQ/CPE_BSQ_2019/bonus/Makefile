##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## for evalexpr
##

SRC	    =	$(wildcard lib/my/*.c) \
		src/main.c \
		src/my_sort_int_array.c \
		src/pre_formating.c \
		src/algorythm.c

OBJ	    =	$(SRC:.c=.o)

NAME	    =	bsq

SRC_TEST    =	$(SRC) $(wildcard tests/*.c)

OBJ_TEST    =	$(SRC_TEST:.c=.o)

TEST	    =	test_run

SRC_MAIN    =	main.c $(SRC)

OBJ_MAIN    =   $(SRC_MAIN:.c=.o)

MAIN	    =	main

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -g3 -o $(NAME) $(OBJ)

tests_run:	$(OBJ_TEST)
		gcc -o $(TEST) $(OBJ_TEST) -lcriterion
		./test_run

run:		$(OBJ_MAIN)
		gcc -o $(MAIN) $(OBJ_MAIN)
		./main

clean:
	rm -f $(OBJ) $(OBJ_TEST) $(OBJ_MAIN)

fclean: clean
	rm -f $(NAME) $(MAIN) $(TEST)

re:	fclean all

.PHONY: all clean fclean re
