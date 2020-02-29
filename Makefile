# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xzhu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 14:55:11 by xzhu              #+#    #+#              #
#    Updated: 2018/07/12 14:55:16 by xzhu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	xzhu.filler

NOC			=	\033[0m
GREEN		=	\033[0;36m
BLUE		=	\033[0;34m
RED			=	\033[0;31m

CC			=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror -g

SRC_PATH	=	./srcs/
INC_PATH	=	./includes/
OBJ_PATH	=	./obj/
LFT_PATH	=	./libftprintf/
MLX_PATH 	= 	./minilibx_macos/

SRC		=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ		=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC			=	$(addprefix -I,$(INC_PATH))

OBJ_NAME	=	$(SRC_NAME:.c=.o)

SRC_NAME	=	filler.c

all:
	@make -C $(LFT_PATH)
	@make -C $(MLX_PATH)
	@make $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -L $(LFT_PATH) -lftprintf
	@echo "$(GREEN)FILLER ✓ Filler ready$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -I $(MLX_PATH) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(BLUE)FILLER ✓ Removed .o files$(NOC)"

fclean: clean
	@make -C $(LFT_PATH) fclean
	@make -C $(MLX_PATH) fclean
	@rm -f $(NAME)
	@echo "$(RED)FILLER ✓ Removed Filler executable$(NOC)"

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
