/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:24:04 by pteixeir          #+#    #+#             */
/*   Updated: 2025/04/03 23:19:47 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_position(t_data *data, int new_x, int new_y)
{
	int		old_x;
	int		old_y;
	char	new_pos;

	old_x = data->map_data->player_position[1];
	old_y = data->map_data->player_position[0];
	data->map_data->player_position[0] = new_y;
	data->map_data->player_position[1] = new_x;
	if (data->map_data->map[new_y][new_x] == 'C')
		data->content->collectible -= 1;
	if (old_y != new_y || old_x != new_x)
	{
		new_pos = data->map_data->map[new_y][new_x];
		data->map_data->map[old_y][old_x] = '0';
		data->map_data->map[new_y][new_x] = 'P';
		data->map_data->moves += 1;
		ft_printf("Moves: %d 🎤\n", data->map_data->moves);
		check_exit_and_update(data, new_pos);
	}
}

void	check_exit_and_update(t_data *data, char new_pos)
{
	if (data->map_data->map[data->map_data->exit_position[0]]
		[data->map_data->exit_position[1]] == '0')
	{
		data->map_data->map[data->map_data->exit_position[0]]
		[data->map_data->exit_position[1]] = 'E';
	}
	if (new_pos == 'E' && data->content->collectible == 0)
	{
		ft_printf("BOW BEFORE THE PRINCE OF ALL SAIYANS!!\n");
		show_end_image(data);
	}
}
#include "so_long.h"

void	move_player(int nx, int ny, t_data *d)
{
	int	x = d->map_data->player_position[1];
	int	y = d->map_data->player_position[0];
	int	t = 48;
	char	n = d->map_data->map[ny][nx];

	if (n == '1' || (n == 'E' && d->map_data->collectibles > 0))
		return;
	if (n == 'E' && d->map_data->collectibles == 0)
		return (show_end_image(d), (void)0);
	if (n == 'C')
		d->map_data->collectibles--;
	d->map_data->moves++;
	d->map_data->map[y][x] = '0';
	d->map_data->map[ny][nx] = 'P';
	d->map_data->player_position[0] = ny;
	d->map_data->player_position[1] = nx;
	mlx_put_image_to_window(d->mlx, d->win, d->img[5], x * t, y * t);
	mlx_put_image_to_window(d->mlx, d->win,
		d->img[d->player_img_index], nx * t, ny * t);
	if (d->player_img_index == FLY_LEFT)
		d->player_img_index = STAND_LEFT;
	else if (d->player_img_index == FLY_RIGHT)
		d->player_img_index = STAND_RIGHT;
	ft_printf("Moves: %d 🟠🐉\n", d->map_data->moves);
}

int	update_player_sprite(int k, t_data *d)
{
	int	x = d->map_data->player_position[1];
	int	y = d->map_data->player_position[0];
	int	nx = x;
	int	ny = y;

	if (k == ESC)
		free_all(d);
	else if ((k == UP_ARROW || k == W_KEY) && (ny-- || 1))
		d->player_img_index = (d->last_horizontal_dir == LEFT_ARROW)
			? FLY_LEFT : FLY_RIGHT;
	else if ((k == DOWN_ARROW || k == S_KEY) && (ny++ || 1))
		d->player_img_index = (d->last_horizontal_dir == LEFT_ARROW)
			? FLY_LEFT : FLY_RIGHT;
	else if ((k == LEFT_ARROW || k == A_KEY) && (nx-- || 1))
		d->player_img_index = FLY_LEFT, d->last_horizontal_dir = LEFT_ARROW;
	else if ((k == RIGHT_ARROW || k == D_KEY) && (nx++ || 1))
		d->player_img_index = FLY_RIGHT, d->last_horizontal_dir = RIGHT_ARROW;
	if (nx != x || ny != y)
		move_player(nx, ny, d);
	return (0);
}




