# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 20:57:11 by juan-her          #+#    #+#              #
#    Updated: 2025/11/22 18:13:39 by juan-her         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
NAME = fractol
SRC_MLX = ./minilibx-linux
INCLUDE_MLX = -L$(SRC_MLX) -lmlx -lXext -lX11 -lm
SRC = main.c utils.c set_data.c render.c julia.c mandelbrot.c handle_key.c
OBJ_URL = ./obj
OBJ = $(SRC:%.c=$(OBJ_URL)/%.o)
RM = rm -rf

all: $(NAME)
	@echo "Fractol ready"

$(NAME): $(OBJ)
	@$(MAKE) -C $(SRC_MLX)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE_MLX) 
	@echo "finish $(NAME)"

$(OBJ_URL):
	@mkdir -p $(OBJ_URL)

$(OBJ_URL)/%.o: %.c | $(OBJ_URL)
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@$(RM) $(OBJ_URL)
	@echo "Objects deleted"

fclean: clean
	@$(RM) $(NAME)
	@echo "Program deleted"

re: fclean all
	@echo "Re Program"

.PHONY: all clean fclean re