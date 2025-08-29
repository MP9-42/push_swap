# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 21:24:53 by MP9               #+#    #+#              #
#    Updated: 2025/08/29 20:49:40 by MP9              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap


OBJ_DIR = objs
SRCFILES = push_swap.c push_swap_utils.c push_swap_create.c
OBJ = $(SRCFILES:srcs/%.c=$(OBJ_DIR)/%.o)
CC = cc
CFLAGS = -Wall -Wextra - Werror -I./includes/ -I./libftV2/includes/

LIBFT_DIR = ./libftV2
LIBFT = $(LIBFT_DIR)/libft.a

all : $(LIBFT) $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(NAME) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c includes/*.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

clean:
		rm -rf $(OBJS)
		$(MAKE) clean -C $(LIBFT_DIR)
		@echo "library and object files cleaned." 

fclean: clean
		rm -f $(NAME)
		$(MAKE) fclean -C $(LIBFT_DIR)
		@echo "library and object files cleaned."

re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY: all bonus clean fclean re 