##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRCDIR	=	src/

SRC=		main2.c							\
		malloc_free.c						\
		lillib/my_getnbr.c					\
		lillib/my_putstr.c					\
		creating_board.c					\
		lillib/my_strlen.c					\
		game_exec.c						\
		ais_turn.c						\
		verif_player.c						\
		get_next_line.c						\
		putstr_errors.c 					\

OBJ=		$(addprefix $(SRCDIR), $(SRC:.c=.o))

CFLAGS=		-I./include

CFLAGS +=	-Wall -Wextra

NAME=		matchstick

all:		$(NAME) clean

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
