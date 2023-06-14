# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 11:51:03 by mivendit          #+#    #+#              #
#    Updated: 2023/05/04 21:36:00 by mivendit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ft_bzero.c ft_itoa.c ft_putendl.c ft_strdel.c \
ft_strequ.c ft_strjoin.c ft_putchar.c ft_putstr.c ft_strlen.c\
ft_strncmp.c ft_strcmp.c ft_atoi.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

OBJ=$(SRC:%.c=%.o)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo	"\t$@ is ready"
	@$(MAKE) --no-print-directory -C ./ft_printf
	@echo	"\tft_printf.a is ready"
	@$(MAKE) --no-print-directory -C ./get_next_line
	@echo	"\tget_next_line.a is ready"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $^

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo '\t$(NAME) object files deleted\n'
	@$(MAKE) > /dev/null 2>&1 clean -C ./ft_printf
	@$(MAKE) > /dev/null 2>&1 clean -C ./get_next_line

fclean: clean
	@rm -f $(NAME)
	@echo '\t$(NAME) deleted\n'
	@$(MAKE) > /dev/null 2>&1 fclean -C ./ft_printf
	@$(MAKE) > /dev/null 2>&1 fclean -C ./get_next_line
re: fclean all

.PHONY: all, clean, fclean, re
