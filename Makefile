# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 20:53:17 by pteixeir          #+#    #+#              #
#    Updated: 2025/03/05 20:53:32 by pteixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/
MLX_DIR = ./mlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
SRCS = *.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I/usr/include -Imlx

all:  $(MLX_LIB) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS): $(SRCS)
	$(CC) -c $(SRCS) $(INCLUDES)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean
	$(MAKE)