# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 20:12:03 by pteixeir          #+#    #+#              #
#    Updated: 2025/02/12 21:59:45 by pteixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
FLAGS = -Wall -Wextra -Werror

MLX_DIR = mlx
LIBFT_DIR = libft
INCLUDE_DIR = include  # Diretório dos headers

MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd

INCLUDES = -I$(INCLUDE_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)

SRC = srcs/main.c srcs/map.c srcs/graphics.c srcs/player.c srcs/utils.c \
      srcs/gnl/get_next_line.c srcs/gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(LIBFT)
	rm -f $(MLX)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
