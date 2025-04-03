/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:28:24 by pteixeir          #+#    #+#             */
/*   Updated: 2025/04/03 22:47:16 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_intro(t_data *data)
{
	int	width;
	int	height;

	width = 1510;
	height = 800;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		print_error_menssage("Failed to initialize mlx\n", data);
	data->win = mlx_new_window(data->mlx, width, height, "Intro");
	if (data->win == NULL)
		print_error_menssage("Failed to create window\n", data);
	data->img = ft_calloc(1, sizeof(void *));
	if (data->img == NULL)
		print_error_menssage("Failed to allocate memory for images\n", data);
	data->img[0] = mlx_xpm_file_to_image(data->mlx, "sprites/IntroVegeta.xpm",
			&width, &height);
	if (data->img[0] == NULL)
		print_error_menssage("Failed to load image\n", data);
	mlx_put_image_to_window(data->mlx, data->win, data->img[0], 0, 0);
	mlx_hook(data->win, 2, 1L << 0, switch_to_main_window, data);
	mlx_loop(data->mlx);
}

void	show_end_image(t_data *data)
{
	int	width;
	int	height;

	width = 1920;
	height = 1080;
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	data->end_win = mlx_new_window(data->mlx, width, height,
			"Vegeta");
	data->end_img = mlx_xpm_file_to_image(data->mlx, "sprites/Outro.xpm",
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->end_win, data->end_img, 0, 0);
	mlx_hook(data->end_win, 2, 1L << 0, close_ending, data);
	mlx_loop(data->mlx);
}

int	switch_to_main_window(int keycode, t_data *data)
{
	(void)keycode;
	if (data->img[0])
	{
		mlx_destroy_image(data->mlx, data->img[0]);
		free(data->img);
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	graphics_initialize(data);
	return (0);
}

int	close_ending(int keycode, t_data *data)
{
	(void)keycode;
	if (data->end_img)
	{
		mlx_destroy_image(data->mlx, data->end_img);
		data->end_img = NULL;
	}
	if (data->end_win)
	{
		mlx_destroy_window(data->mlx, data->end_win);
		data->end_win = NULL;
	}
	free_all(data);
	return (0);
}

void	graphics_initialize(t_data *data)
{
	int	width;
	int	height;

	width = (data->map_data->columns) * 48;
	height = (data->map_data->lines) * 48;
	data->win = mlx_new_window(data->mlx, width, height, "Vegeta");
	data->last_horizontal_dir = RIGHT_ARROW;
	load_player_sprites(data);
	count_collectibles(data);
	render_sprites(data, -1, -1);
	mlx_hook(data->win, 2, 1L << 0, update_player_sprite, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == LEFT_ARROW || keycode == A_KEY)
		data->player_img_index = STAND_LEFT;
	else if (keycode == RIGHT_ARROW || keycode == D_KEY)
		data->player_img_index = STAND_RIGHT;

	int x = data->map_data->player_position[1];
	int y = data->map_data->player_position[0];
	int t = 48;

	mlx_put_image_to_window(data->mlx, data->win, data->img[5], x * t, y * t);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img[data->player_img_index], x * t, y * t);

	return (0);
}
