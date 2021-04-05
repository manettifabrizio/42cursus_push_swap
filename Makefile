# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 17:06:32 by fmanetti          #+#    #+#              #
#    Updated: 2021/04/05 17:49:31 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CHECK		=	checker

FILES		=	checker.c					\
				execute_instructions.c		\
				instructions.c				\
				stack_utils.c				\
				check_errors.c

HFILES		=	push_swap.h

LIB			=	libft.a

SOURCE		=	$(addprefix ./srcs/, $(FILES))
HEADERS		=	$(addprefix ./include/, $(HFILES))
INCLUDE		=	$(addprefix ./include/libft/, $(LIB))

OBJ			=	$(SOURCE:%.c=%.o)

CC			= 	clang

CFLAGS		=   -I include/ -Wall -Wextra -Werror
FSANITIZE	= 	-g3 -O0 -fsanitize=address

RED			=	\e[0;31m
GREEN		=	\e[0;32m
WHITE		=	\e[0m

all: $(CHECK)

$(CHECK): $(OBJ) $(HEADERS) $(INCLUDE)
	@printf "[ $(CHECK) ] Compiling...\r"
	@($(CC) -o $(CHECK) $(SOURCE) $(INCLUDE) $(CFLAGS) $(FSANITIZE))
	@printf "[ $(CHECK) ] Created $(GREEN)Successfully\n$(WHITE)" $(SUCCESS)

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
	@/bin/rm -rf $(CHECK)*
	@/bin/rm -rf .vscode
	@printf "[ $(CHECK) ] ${RED}removed\n${WHITE}"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
