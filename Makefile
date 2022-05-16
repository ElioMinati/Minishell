##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile for minishell1
##

SRC	=	main.c	\
		src/input_handler.c	\
		src/set.c	\
		src/get.c	\
		src/env.c	\
		src/cd_handling.c	\
		src/builtin_handler.c	\
		src/verif.c	\
		src/mysh.c	\
		src/cd_get.c	\
		src/pipes.c	\
		src/dup_to_std.c	\
		src/detect_bin.c	\
		src/multiple_pipes.c	\
		src/input_redirection.c

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-Llib/my/ -lmy

CFLAGS	=	-Wall -Wextra -g

CPPFLAGS	=	-Iinclude/

CCRITERION	= 	--coverage -lcriterion

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	make clean -C lib/my
	$(RM) $(NAME)

re: fclean all

.PHONY : all re clean tests_run fclean
