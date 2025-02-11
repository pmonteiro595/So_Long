# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 20:12:03 by pteixeir          #+#    #+#              #
#    Updated: 2025/02/05 23:00:32 by pteixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
FLAGS = -Wall -Wextra -Werror

MLX_DIR = mlx
LIBFT_DIR = libft

MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L /usr/include/../lib -lXext -lX11 -lm -lbsd

MLX_INC = -I $(MLX_DIR)
LIBFT_INC = -I $(LIBFT_DIR)
INCLUDES = $(MLX_INC) $(LIBFT_INC)

SRC = so_long.c map_reader.c graphics.c player.c utils.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(MLX) so_long

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

so_long: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o so_long

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(LIBFT)
	rm -f $(MLX)
	rm -f so_long

re: fclean all

.PHONY: all clean fclean re
	