# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 09:50:39 by afavre            #+#    #+#              #
#    Updated: 2022/12/06 10:39:02 by afavre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
NAME		= push_swap

SRC_PATH	= src/
OBJ_PATH	= obj/

LIB_DIR		= libft
LIB_NAME	= ./libft/lib.a

SRC			= main.c \
			input_check.c input_check_utils.c \
			initialization.c \
			stack.c \
			swap.c push.c rotate.c reverse_rotate.c \
			sort_tiny.c sort.c \
			position.c cost.c do_move.c \
			utils.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
INCS		= -I ./includes/

all: $(OBJ_PATH) $(NAME) 

lib_compile :
			@make -C $(LIB_DIR)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS) lib_compile
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_NAME) -o $(NAME)
	@echo "$(GREEN)Allez cette fois a toi de bosser !$(DEF_COLOR)"

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf $(LIB_NAME)
	@echo "$(CYAN)C'est tout de suite mieux !$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)Et ben ! ca fait de la place !$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re