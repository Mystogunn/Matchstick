##
## Makefile for Makefile in /home/Mystogun/exopis
##
## Made by Josselin COSMAO
## Login   <Mystogun@epitech.net>
##
## Started on  Sat Oct 15 16:46:52 2016 Josselin COSMAO
## Last update Sun Feb 26 11:23:42 2017 Josselin
##

CC	= gcc

RM	= rm -rf

NAME	= matchstick

SRCS	= main.c \
	  algo.c \
	  algo2.c \
	  my_function.c \
	  my_function2.c \
	  get_next_line.c \
	  check_error.c \
	  player.c \
	  ia.c \
	  check_game.c \
	  check_error2.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+=  -Wextra -Wall -g3 -Iinclude/

all:	$(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
