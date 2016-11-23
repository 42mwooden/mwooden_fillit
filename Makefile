# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwooden <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 11:14:02 by mwooden           #+#    #+#              #
#    Updated: 2016/11/23 12:14:41 by mwooden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES =\
		   main.c\
		   error.c\
		   parser.c

INCLUDES =\
		  libft.h\
		  fillit.h

NAME = fillit

SRCS = $(FILENAMES)

CC = gcc

CFLAGS ?= -Wall -Wextra -Werror
CFLAGS += -I $(INCLUDES)
CFLAGS += -L./ -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): 
	$(CC) $(SRCS) $(CFLAGS)
