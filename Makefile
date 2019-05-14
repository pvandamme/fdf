# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmerien <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 07:40:44 by rmerien           #+#    #+#              #
#    Updated: 2019/05/14 22:51:34 by pvandamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = 	$(addprefix $(SRCS_PATH)/, main.c \
		init_map.c 		\
		pv.c 			\
		print.c 		\
		projection.c 	\
		key_input.c		\
		utils.c			\
		colors.c)
OBJS =  $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)
INCLUDES = includes minilibx libft/includes
MLX = $(MLX_PATH)/libmlx.a
MLX_PATH = minilibx
LIB = $(LIB_PATH)/libft.a
LIB_PATH = libft
CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit
GREEN = \033[01;32m
YELLOW = \033[01;33m
CYAN = \033[01;36m
RESET = \033[00m

all: $(NAME)

$(NAME): $(MLX) $(LIB) $(OBJS)
	@$(CC) $(MLX_FLAGS) -o $@ $^
	@echo "$(GREEN)$@ : compilation OK$(RESET)"

$(LIB):
	@make -C $(LIB_PATH)
	@echo "$(GREEN)$(LIB) : compilation OK$(RESET)"

$(MLX):
	@make -C $(MLX_PATH)
	@echo "$(GREEN)$(MLX) : compilation OK$(RESET)"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c $(INCLUDES)
	@$(CC) -o $@ -c $< $(addprefix -I , $(INCLUDES))
	@echo "$@ : $(YELLOW)OK$(RESET)"

clean:
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIB_PATH)
	@echo "clean $(LIB_PATH)/objs : $(CYAN)clean$(RESET)"
	@rm -f $(OBJS)
	@echo "clean $(OBJS): $(CYAN)clean$(RESET)"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@echo "clean $(LIB) : $(CYAN)clean$(RESET)"
	@rm -f $(NAME)
	@echo "clean $(NAME) : $(CYAN)clean$(RESET)"

re: fclean all

.PHONY: clean fclean re
