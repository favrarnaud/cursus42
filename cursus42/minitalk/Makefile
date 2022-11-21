# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 10:35:33 by afavre            #+#    #+#              #
#    Updated: 2022/11/21 10:13:44 by afavre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_SRV		= server
NAME_CLIENT		= client
INCLUDE			= ./include
LIB_DIR			= printf
LIB_NAME		= lib.a
SRC_DIR			= src/
OBJ_DIR			= obj/
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra 
RM				= rm -rf
AR				= ar rcs


DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# SERVER
SRC_FILES_SRV		= main_srv

# CLIENT
SRC_FILES_CLIENT	= main_client


SRC_SRV 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_SRV)))
OBJ_SRV 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_SRV)))

SRC_CLIENT 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_CLIENT)))
OBJ_CLIENT 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_CLIENT)))

OBJF		=	.cache_exists

all:		lib_compile $(NAME_SRV) $(NAME_CLIENT)


$(NAME_SRV):	$(OBJ_SRV)
			@$(CC) -o $(NAME_SRV) $(OBJ_SRV) $(LIB_NAME)
			@echo "$(GREEN)SERVER compiled!$(DEF_COLOR)"

$(NAME_CLIENT):	$(OBJ_CLIENT)
			@$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIB_NAME)
			@echo "$(GREEN)CLIENT compiled!$(DEF_COLOR)"

lib_compile :
			@make -C $(LIB_DIR)
			@cp ./printf/libftprintf.a ./lib.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:		
			@make clean -C $(LIB_DIR)
			@$(RM) $(OBJ_DIR)
			@echo "$(BLUE)Object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@make fclean -C $(LIB_DIR)
			@$(RM) $(LIB_NAME)
			@$(RM) -f $(NAME_SRV)
			@$(RM) -f $(NAME_CLIENT)

			@echo "$(CYAN)Executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for GNL!$(DEF_COLOR)"

.PHONY:		all clean fclean re libft
