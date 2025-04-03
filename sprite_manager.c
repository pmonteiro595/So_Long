/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:20:59 by pteixeir          #+#    #+#             */
/*   Updated: 2025/04/03 21:55:56 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	load_player_sprites(t_data *data)
{
	int i;

	data->img = ft_calloc(sizeof(void *), 8);
	i = 48;
	data->img[0] = mlx_xpm_file_to_image(data->mlx, "sprites/Standing_Vegeta_NB.xpm", &i, &i);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, "sprites/Vegeta_standing_back.xpm", &i, &i);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, "sprites/collectible.xpm", &i, &i);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, "sprites/saiyan_pod_exit.xpm", &i, &i);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "sprites/brick_wall.xpm", &i, &i);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, "sprites/background.xpm", &i, &i);
	data->img[6] = mlx_xpm_file_to_image(data->mlx, "sprites/vegeta_fly_left.xpm", &i, &i);
	data->img[7] = mlx_xpm_file_to_image(data->mlx, "sprites/vegeta_fly_right.xpm", &i, &i);
}

void	render_sprites(t_data *data, int i, int g)
{
	while (++i < data->map_data->lines && data->map_data->map[i] != NULL)
	{
		g = -1;
		while (++g < data->map_data->columns && data->map_data->map[i] != NULL)
		{
			if (data->map_data->map[i][g] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img[4],
					g * 48, i * 48);
			else if (data->map_data->map[i][g] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img[5],
					g * 48, i * 48);
			else if (data->map_data->map[i][g] == 'P')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[data->player_img_index], g * 48, i * 48);
			else if (data->map_data->map[i][g] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img[2],
					g * 48, i * 48);
			else if (data->map_data->map[i][g] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img[3],
					g * 48, i * 48);
		}
	}
}

int	close_window(t_data *data)
{
	free_all(data);
	return (0);
}
