##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/my_error.c			\
		src/my_getnbr.c			\
		src/my_matchstick.c		\
		src/my_matchgame.c		\
		src/get_next_line.c		\
		src/my_string.c			\
		src/my_itoa.c			\
		src/my_rm_pipe.c		\
		src/my_bot_play.c		\
		src/my_game_over.c		\
		src/my_line_error_check.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -I./include

CC	=	gcc

NAME	=	matchstick

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)	\
	rm -rf *~
	rm -rf *.a

re: clean all

.PHONY: all re clean fclean
