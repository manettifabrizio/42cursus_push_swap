# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 17:06:32 by fmanetti          #+#    #+#              #
#    Updated: 2021/04/04 12:09:40 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Checker

FILES		=	checker.c

HFILES		=	push_swap.h

LIB			=	libft.a

SOURCE		=	$(addprefix ./srcs/, $(FILES))
HEADERS		=	$(addprefix ./include/, $(HFILES))
INCLUDE		=	$(addprefix ./include/libft/, $(LIB))

OBJ			=	$(SOURCE:%.c=%.o)

CC			= 	clang

CFLAGS		=   -I include/ -Wall -Wextra -Werror
FSANITIZE	= 	-g3 -O0 -fsanitize=address

RED			=	\033[0;31m
GREEN		=	\033[0;32m
WHITE		=	\033[0m

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS) $(INCLUDE)
	@printf "[ $(NAME) ] Compiling...\r"
	@($(CC) -o $(NAME) $(SOURCE) $(INCLUDE) $(CFLAGS) $(FSANITIZE))
	@printf "[ $(NAME) ] Created $(GREEN)Successfully\n$(WHITE)" $(SUCCESS)

lib:
	@make re bonus -C include/libft
	@make clean -C include/libft

key:
	@gcc -o key keycode.c $(CFLAGS)
	@./key
	@rm key

clean:
	@/bin/rm -f $(OBJ)
	@printf "Object files ${RED}removed\n${WHITE}"

fclean: clean
	@/bin/rm -rf $(NAME)*
	@/bin/rm -rf .vscode .minish_history
	@printf "[ $(NAME) ] ${RED}removed\n${WHITE}"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
