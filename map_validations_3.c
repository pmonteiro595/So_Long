/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:52:23 by pteixeir          #+#    #+#             */
/*   Updated: 2025/03/05 20:52:33 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_and_exit_position(char **map, t_data *data)
{
	int	i;
	int	g;

	i = 0;
	while (map[i] != NULL)
	{
		g = 0;
		while (map[i][g] != '\0')
		{
			if (map[i][g] == 'P')
			{
				data->map_data->player_position[0] = i;
				data->map_data->player_position[1] = g;
			}
			else if (map[i][g] == 'E')
			{
				data->map_data->exit_position[0] = i;
				data->map_data->exit_position[1] = g;
			}
			g++;
		}
		i++;
	}
}

void	flood_fill(char **map, int i, int g, t_data *data)
{
	if (i < 0 || g < 0 || i >= data->map_data->lines
		|| g >= data->map_data->columns)
		return ;
	if (map[i][g] == '1' || map[i][g] == 'G')
		return ;
	map[i][g] = 'G';
	flood_fill(map, i + 1, g, data);
	flood_fill(map, i - 1, g, data);
	flood_fill(map, i, g + 1, data);
	flood_fill(map, i, g - 1, data);
}

int	check_dummy_map(char **map)
{
	int	i;
	int	g;

	i = 0;
	while (map[i] != NULL)
	{
		g = 0;
		while (map[i][g] != '\0')
		{
			if (map[i][g] == '0' || map[i][g] == 'C' || map[i][g] == 'E')
				return (0);
			g++;
		}
		i++;
	}
	return (1);
}
