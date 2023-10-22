# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktorvi <ktorvi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 07:03:04 by ktorvi            #+#    #+#              #
#    Updated: 2023/10/03 14:11:45 by ktorvi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src
INC_DIR = includes
LIBFT_DIR = libft

SRCS = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(SRCS:.c=.o)

INC = -I $(INC_DIR) -I $(LIBFT_DIR)

LIBS = -L $(LIBFT_DIR) -lft

NAME = libftprintf.a

all: $(NAME)


$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)


%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

