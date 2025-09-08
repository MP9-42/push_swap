# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 21:24:53 by MP9               #+#    #+#              #
#    Updated: 2025/09/08 00:39:20 by MP9              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
OBJ_DIR = objs
SRCFILES =	srcs/push_swap.c srcs/push_swap_utils.c srcs/push_swap_parsing.c srcs/push_swap_list.c \
			srcs/push_swap_utils2.c \
			
OBJS = $(SRCFILES:srcs/%.c=$(OBJ_DIR)/%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./libft/includes/

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all : $(LIBFT) $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c includes/*.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

clean:
		rm -rf $(OBJ_DIR)
		$(MAKE) clean -C $(LIBFT_DIR)
		@echo "library and object files cleaned." 

fclean: clean
		rm -f $(NAME)
		$(MAKE) fclean -C $(LIBFT_DIR)
		@echo "Executable and library cleaned."

re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY: all bonus clean fclean re 