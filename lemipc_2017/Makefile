##
## EPITECH PROJECT, 2018
## Makefile
## File description:
##
##

SRCS	=	src/help.c		\
		src/prepare_board.c	\
		src/shared_mem.c	\
		src/team_players.c	\
		src/player_loop.c	\
		src/incr_sem.c		\
		src/moves.c		\
		src/get_kill.c		\
		src/message_queue.c	\
		src/main.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	lemipc

CC	=	gcc -g

LDFLAGS	=	-W -Wall -Wextra -Werror

LIB	=	-lncurses

$(NAME):	$(OBJS) 
		$(CC) $(LDFLAGS) $(OBJS) $(LIB) -o $(NAME)

all:		$(NAME)

re:		fclean all

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

.PHONY:		all clean fclean re
