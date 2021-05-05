# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 17:06:32 by fmanetti          #+#    #+#              #
#    Updated: 2021/05/03 12:10:11 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CHECK			=	checker

FILE_PUSH_SWAP	=	push_swap.c
FILE_CHECKER	=	checker.c
FILES_PATH		=	./srcs/

FILES			=	operations/execute.c		\
					operations/operations.c		\
					operations/debug_mode.c		\
					sort/choose_rotation.c		\
					sort/three_to_five.c		\
					sort/chunks.c				\
					sort/create_chunks.c		\
					sort/optimize_rotation.c	\
					utils/options.c				\
					utils/sort_utils.c			\
					utils/create_stacks.c		\
					utils/stack_utils.c			\
					utils/check_errors.c		\
					utils/print_stacks.c		\
					utils/debug_utils.c

HFILES			=	push_swap.h
HFILES_PATH		=	./include/

LIB				=	libft.a
LIB_PATH		=	./include/libft/

PUSH_SWAP		=	$(addprefix $(FILES_PATH), $(FILE_PUSH_SWAP))
CHECKER			=	$(addprefix $(FILES_PATH), $(FILE_CHECKER))
SOURCE			=	$(addprefix $(FILES_PATH), $(FILES))
HEADERS			=	$(addprefix $(HFILES_PATH), $(HFILES))
LIBRARY			=	$(addprefix $(LIB_PATH), $(LIB))

OBJ				=	$(PUSH_SWAP:%.c=%.o) $(CHECKER:%.c=%.o) $(SOURCE:%.c=%.o)

CC				= 	clang

CFLAGS			=   -I $(HFILES_PATH) -Wall -Wextra -Werror
FSANITIZE		= 	-g3 -O0 -fsanitize=address

RED				=	\033[0;31m
GREEN			=	\033[0;32m
BOLD			=	\033[1m
RESET		=	\033[0m

all: $(NAME) $(CHECK)

$(NAME): $(PUSH_SWAP) $(OBJ) $(HEADERS) $(LIBRARY)
	@printf "[ $(NAME) ] Compiling...\r"
	@($(CC) -o $(NAME) $(PUSH_SWAP) $(SOURCE) $(LIBRARY) $(CFLAGS))

$(CHECK): $(CHECKER) $(OBJ) $(HEADERS) $(LIBRARY)
	@printf "[ $(CHECK) ] Compiling...\r"
	@($(CC) -o $(CHECK) $(CHECKER) $(SOURCE) $(LIBRARY) $(CFLAGS))
	@printf "${GREEN}"
	@printf "                                oooo                                                                 \n"
	@printf "                                '888                                                                 \n"
	@printf "oo.ooooo.  oooo  oooo  .oooo.o  888 .oo.                .oooo.o oooo oooo    ooo  .oooo.   oo.ooooo. \n"
	@printf "888' '88b '888  '888  d88(  '8  888P'Y88b              d88(  '8  '88. '88.  .8'  'P  )88b  888' '88b \n"
	@printf "888   888  888   888  'Y88b.    888   888              'Y88b.     '88..]88..8'    .oP'888  888   888 \n"
	@printf "888   888  888   888  o.  )88b  888   888              o.  )88b    '888'888'     d8(  888  888   888 \n"
	@printf "888bod8P'  'V88V'V8P'  8'888P' o888o o888o ooooooooooo  8'888P'     '8'  '8'     'Y888'8o  888bod8P' \n"
	@printf "888                                                                                        888       \n"
	@printf "o888o                                                                                      o888o     \n"
	@printf "$(RESET)"
	@printf "┏┓ ╻ ╻   ┏━╸┏┳┓┏━┓┏┓╻┏━╸╺┳╸╺┳╸╻     ┏━╸┏━┓┏┳┓┏━┓╻╻  ┏━╸╺┳┓      $(GREEN)┏━┓╻ ╻┏━╸┏━╸┏━╸┏━┓┏━┓┏━╸╻ ╻╻  ╻  ╻ ╻\n$(RESET)"
	@printf "┣┻┓┗┳┛   ┣╸ ┃┃┃┣━┫┃┗┫┣╸  ┃  ┃ ┃     ┃  ┃ ┃┃┃┃┣━┛┃┃  ┣╸  ┃┃      $(GREEN)┗━┓┃ ┃┃  ┃  ┣╸ ┗━┓┗━┓┣╸ ┃ ┃┃  ┃  ┗┳┛\n$(RESET)"
	@printf "┗━┛ ╹    ╹  ╹ ╹╹ ╹╹ ╹┗━╸ ╹  ╹ ╹     ┗━╸┗━┛╹ ╹╹  ╹┗━╸┗━╸╺┻┛      $(GREEN)┗━┛┗━┛┗━╸┗━╸┗━╸┗━┛┗━┛╹  ┗━┛┗━╸┗━╸ ╹ \n$(RESET)"
	@printf "See '$(BOLD)make help$(RESET)' for checker options or '$(BOLD)bash test/test.sh -h$(RESET)' for tester options.\n"

san: $(NAME)_san $(CHECK)_san

$(NAME)_san: $(PUSH_SWAP) $(OBJ) $(HEADERS) $(LIBRARY)
	@printf "[ $(NAME) ] Compiling with fsanitize...\r"
	@($(CC) -o $(NAME) $(PUSH_SWAP) $(SOURCE) $(LIBRARY) $(CFLAGS) $(FSANITIZE))
	@printf "[ $(NAME) ] Created $(GREEN)Successfully$(RESET) with fsanitize\n" $(SUCCESS)

$(CHECK)_san: $(CHECKER) $(OBJ) $(HEADERS) $(LIBRARY)
	@printf "[ $(CHECK) ] Compiling with fsanitize...\r"
	@($(CC) -o $(CHECK) $(CHECKER) $(SOURCE) $(LIBRARY) $(CFLAGS) $(FSANITIZE))
	@printf "[ $(CHECK) ] Created $(GREEN)Successfully$(RESET) with fsanitize\n" $(SUCCESS)

help:
	@printf "$(BOLD)Usage:$(RESET) ARG=\"1 2 3\"; ./push_swap $$"ARG" | ./checker $$"ARG"\n"
	@printf "./checker  [ -dcov ] [ -c activate colors ]\n"
	@printf "                     [ -d display mode ]\n"
	@printf "                     [ -o print number of operations ]\n"
	@printf "                     [ -v debug mode ] [ arguments ]\n"

lib:
	@make re bonus -C $(LIB_PATH)
	@make clean -C $(LIB_PATH)

clean:
	@/bin/rm -f $(OBJ)
	@printf "Object files $(RED)removed\n$(RESET)"

fclean: clean
	@/bin/rm -rf $(NAME)* $(CHECK)*
	@/bin/rm -rf .vscode
	@printf "[ $(NAME) ] $(RED)removed\n$(RESET)"
	@printf "[ $(CHECK) ] $(RED)removed\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
