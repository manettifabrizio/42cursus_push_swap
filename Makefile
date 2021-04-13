# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 17:06:32 by fmanetti          #+#    #+#              #
#    Updated: 2021/04/13 16:25:58 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CHECK			=	checker

FILES			=	checker.c					\
					execute_instructions.c		\
					instructions.c				\
					stack_utils.c				\
					check_errors.c
FILES_PATH		=	./srcs/

HFILES			=	push_swap.h
HFILES_PATH		=	./include/

LIB				=	libft.a
LIB_PATH		=	./include/libft/

SOURCE			=	$(addprefix $(FILES_PATH), $(FILES))
HEADERS			=	$(addprefix $(HFILES_PATH), $(HFILES))
LIBRARY			=	$(addprefix $(LIB_PATH), $(LIB))

OBJ				=	$(SOURCE:%.c=%.o)

CC				= 	clang

CFLAGS			=   -I $(HFILES_PATH) -Wall -Wextra -Werror
FSANITIZE		= 	-g3 -O0 -fsanitize=address

RED				=	\033[0;31m
GREEN			=	\033[0;32m
NO_COLOR		=	\033[0m

all: $(CHECK)

$(CHECK): $(OBJ) $(HEADERS) $(LIBRARY)
	@printf "[ $(CHECK) ] Compiling...\r"
	@($(CC) -o $(CHECK) $(SOURCE) $(LIBRARY) $(CFLAGS))
	@printf "[ $(CHECK) ] Created $(GREEN)Successfully\n$(NO_COLOR)" $(SUCCESS)

san: $(OBJ) $(HEADERS) $(LIBRARY)
	@printf "[ $(CHECK) ] Compiling with fsanitize...\r"
	@($(CC) -o $(CHECK) $(SOURCE) $(LIBRARY) $(CFLAGS) $(FSANITIZE))
	@printf "[ $(CHECK) ] Created $(GREEN)Successfully$(NO_COLOR) with fsanitize\n" $(SUCCESS)

lib:
	@make re bonus -C $(LIB_PATH)
	@make clean -C $(LIB_PATH)

clean:
	@/bin/rm -f $(OBJ)
	@printf "Object files $(RED)removed\n$(NO_COLOR)"

fclean: clean
	@/bin/rm -rf $(CHECK)*
	@/bin/rm -rf .vscode
	@printf "[ $(CHECK) ] $(RED)removed\n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
