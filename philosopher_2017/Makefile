##
## EPITECH PROJECT, 2018
## philosopher
## File description:
## Makefile
##

NAME	=	philo

CC	=	gcc

RM	=	rm -f

DIR	=	src

SRCS	=	$(DIR)/main.c 			\
		$(DIR)/save_philo.c 		\
		$(DIR)/create_philo.c		\
		$(DIR)/actions.c		\
		$(DIR)/help.c

OBJS	=	$(SRCS:.c=.o)

LDFLAGS	=	-L. -lriceferee -pthread

CFLAGS	=	-I ./
CFLAGS	+=	-W -Wall -Wextra 

all:		$(NAME)

$(NAME): 	$(OBJS)
	 	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
