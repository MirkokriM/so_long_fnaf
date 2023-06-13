# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 17:12:43 by egiubell          #+#    #+#              #
#    Updated: 2023/06/06 17:22:05 by egiubell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I./include -O2

LIBFT = ./mini-libft/libft.a
PRINTF = ./mini-libft/ft_printf/libftprintf.a
GNL = ./mini-libft/get_next_line/get_next_line.a

SEPARATOR = "\033[1m ******************************* \033[0m"
SRC =	\
		./source/so_long.c \
		./utils/init_map.c \
		./utils/checks_errors.c \
		./utils/so_long_utils.c \
		./utils/close_manage.c \
		./graphics/mlx_manage.c \
		./graphics/image_manage.c \
		./graphics/hook_manage.c \
		./graphics/move_manage.c \

OBJS = $(SRC:.c=.o)

ifeq ($(shell uname), Darwin)
    MLX_LIBS += -L./minilibx -lmlx -framework OpenGL -framework AppKit
else
    MLX_LIBS += -L./minilibx -lmlx -lXext -lX11 -lm -lbsd
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -C ./mini-libft
	@echo $(SEPARATOR)
	@echo "\033[1m Mini-LIBFT done \033[0m"
	@$(MAKE) > /dev/null 2>&1 --no-print-directory -C ./minilibx
	@echo "\033[1m MiniLibX done \033[0m"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIBS) $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)
	@echo "\033[1m READY TO START! \033[0m"
	@echo $(SEPARATOR)

%.o: %.c
	@printf "\tCompiling $<...\n"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\tCompiled!\n"

clean:
	@$(MAKE) > /dev/null 2>&1 clean -C ./mini-libft	
	@echo $(SEPARATOR)
	@rm -rf $(OBJS)
	@echo "\033[1m OBJ deleted \033[0m"

fclean: clean
	@$(MAKE) > /dev/null 2>&1 fclean -C ./mini-libft
	@rm -rf $(NAME)
	@echo "\033[1m $(NAME) deleted \033[0m"
	@echo $(SEPARATOR)
re: fclean all

.PHONY: all, clean, fclean, re, bonus
