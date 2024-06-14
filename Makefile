# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalissa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 12:17:17 by aalissa           #+#    #+#              #
#    Updated: 2024/03/21 16:46:24 by aalissa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
SRC :=  main.c	push_swap_commands.c	rota_commands.c	utils.c	error_handle.c	set_price.c	ft_split.c	push_commands.c	swap_commands.c	list_init.c	rev_rota_commands.c	tiny_sort.c
OBJ := $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
