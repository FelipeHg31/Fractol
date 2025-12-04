# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 20:57:11 by juan-her          #+#    #+#              #
#    Updated: 2025/12/04 18:15:22 by juan-her         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -Iminilibx-linux -O3
NAME = fractol
NAME_BONUS = fractol_bonus
SRC_MLX = ./minilibx-linux
INCLUDE_MLX = -L$(SRC_MLX) -lmlx -lXext -lX11 -lm
SRC = main.c utils.c set_data.c render.c create.c fractals.c handle_key.c
SRC_BONUS = main_bonus.c utils_bonus.c set_data_bonus.c render_bonus.c \
			create_bonus.c fractals_bonus.c handle_key_bonus.c
OBJ_URL = ./obj
OBJ_URL_BONUS = ./obj_bonus
OBJ = $(SRC:%.c=$(OBJ_URL)/%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_URL)/%.o)
RM = rm -rf

all: $(NAME)
	@echo "Fractol ready"

$(NAME): $(OBJ)
	@$(MAKE) -C $(SRC_MLX)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE_MLX)
	@echo "finish $(NAME)"

$(NAME_BONUS): $(OBJ_BONUS)
	@$(MAKE) -C $(SRC_MLX)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(INCLUDE_MLX)
	@echo "finish $(NAME_BONUS)"

$(OBJ_URL):
	@mkdir -p $(OBJ_URL)

$(OBJ_URL_BONUS):
	@mkdir -p $(OBJ_URL_BONUS)

$(OBJ_URL)/%.o: %.c | $(OBJ_URL)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_URL_BONUS)/%.o: %.c | $(OBJ_URL_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(NAME_BONUS)

clean:
	@$(RM) $(OBJ_URL_BONUS)
	@$(RM) $(OBJ_URL)
	@echo "Objects deleted"

fclean: clean
	@$(RM) $(NAME_BONUS)
	@$(RM) $(NAME)
	@echo "Program deleted"

re: fclean all
	@echo "Re Program"

.PHONY: all clean fclean re
