# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 17:34:44 by fdagbert          #+#    #+#              #
#    Updated: 2018/02/08 16:13:58 by fdagbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
SRC_PATH = ./
SRC_NAME =	main.c				\
			ft_checktetri.c		\
			ft_newlist.c		\
			ft_reinitlist.c		\
			ft_resolve.c		\
			ft_place.c			\
			ft_memset.c			\
			ft_bzero.c			\
			ft_putchar.c		\
			ft_putstr.c

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_PATH = ./obj
OBJ_NAME = $(SRC_NAME:.c=.o)

HEAD_PATH = ./
CPPFLAGS = -I$(HEAD_PATH)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, fclean, re, norme

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(HEAD_PATH)/*.h
