# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 17:06:32 by fmanetti          #+#    #+#              #
#    Updated: 2021/04/13 18:19:58 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CHECK			=	checker

FILE_PUSH_SWAP	=	push_swap.c
FILE_CHECKER	=	checker.c
S_PATH			=	./srcs/

FILES			=	execute_instructions.c		\
					instructions.c				\
					stack_utils.c				\
					check_errors.c
FILES_PATH		=	./srcs/utils/

HFILES			=	push_swap.h
HFILES_PATH		=	./include/

LIB				=	libft.a
LIB_PATH		=	./include/libft/

PUSH_SWAP		=	$(addprefix $(S_PATH), $(FILE_PUSH_SWAP))
CHECKER			=	$(addprefix $(S_PATH), $(FILE_CHECKER))
SOURCE			=	$(addprefix $(FILES_PATH), $(FILES))
HEADERS			=	$(addprefix $(HFILES_PATH), $(HFILES))
LIBRARY			=	$(addprefix $(LIB_PATH), $(LIB))

OBJ				=	$(PUSH_SWAP:%.c=%.o) $(CHECKER:%.c=%.o) $(SOURCE:%.c=%.o)

CC				= 	gcc

CFLAGS			=   -I $(HFILES_PATH) -Wall -Wextra -Werror
FSANITIZE		= 	-g3 -O0 -fsanitize=address

RED				=	\033[0;31m
GREEN			=	\033[0;32m
NO_COLOR		=	\033[0m

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS) $(LIBRARY)
	@printf "[ $(NAME) ] Compiling...\r"
	@($(CC) -o $(NAME) $(PUSH_SWAP) $(SOURCE) $(LIBRARY) $(CFLAGS))
	@printf "[ $(NAME) ] Created $(GREEN)Successfully\n$(NO_COLOR)" $(SUCCESS)
	@printf "[ $(CHECK) ] Compiling...\r"
	@($(CC) -o $(CHECK) $(CHECKER) $(SOURCE) $(LIBRARY) $(CFLAGS))
	@printf "[ $(CHECK) ] Created $(GREEN)Successfully\n$(NO_COLOR)" $(SUCCESS)

san: $(OBJ) $(HEADERS) $(LIBRARY)
	@printf "[ $(NAME) ] Compiling with fsanitize...\r"
	@($(CC) -o $(NAME) $(PUSH_SWAP) $(SOURCE) $(LIBRARY) $(CFLAGS) $(FSANITIZE))
	@printf "[ $(NAME) ] Created $(GREEN)Successfully$(NO_COLOR) with fsanitize\n" $(SUCCESS)
	@printf "[ $(CHECK) ] Compiling with fsanitize...\r"
	@($(CC) -o $(CHECK) $(CHECKER) $(SOURCE) $(LIBRARY) $(CFLAGS) $(FSANITIZE))
	@printf "[ $(CHECK) ] Created $(GREEN)Successfully$(NO_COLOR) with fsanitize\n" $(SUCCESS)

lib:
	@make re bonus -C $(LIB_PATH)
	@make clean -C $(LIB_PATH)

clean:
	@/bin/rm -f $(OBJ)
	@printf "Object files $(RED)removed\n$(NO_COLOR)"

fclean: clean
	@/bin/rm -rf $(NAME)* $(CHECK)*
	@/bin/rm -rf .vscode
	@printf "[ $(NAME) ] $(RED)removed\n$(NO_COLOR)"
	@printf "[ $(CHECK) ] $(RED)removed\n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
