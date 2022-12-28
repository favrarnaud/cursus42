# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 16:26:45 by afavre            #+#    #+#              #
#    Updated: 2022/12/19 15:19:38 by afavre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
INCLUDE			= ./include
LIB_DIR			= libft
LIB_NAME		= libft/lib.a miniLibX/libmlx.a
LIBX_DIR 		= miniLibX
LIBX_NAME		= libx.a
SRC_DIR			= src/
OBJ_DIR			= obj/
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra 
RM				= rm -rf


DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES	=	main \
				event_handler \
				libx_handler \
				check_file \
				error_handler \
				map_handler \
				check_map \
				sprite_handler \
				data_handler \
				movement_handler \
				utils \
				check_solve \
				floodfill \
				map_utils \
				utils2

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

all:		lib_compile $(NAME)


$(NAME):	$(OBJ)
			@$(CC) -L miniLibX -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) $(LIB_NAME)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

lib_compile :
			@make -C $(LIB_DIR)
			@make -C $(LIBX_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:		
			@make clean -C $(LIB_DIR)
			@make clean -C $(LIBX_DIR)
			@$(RM) $(OBJ_DIR)
			@$(RM) $(LIB_NAME)
			@echo "$(BLUE)Object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@make fclean -C $(LIB_DIR)
			@$(RM) $(NAME)

			@echo "$(CYAN)Executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"

run: all
			./so_long maps/map.ber

.PHONY:		all clean fclean re libft