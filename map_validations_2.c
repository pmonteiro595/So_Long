/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:51:53 by pteixeir          #+#    #+#             */
/*   Updated: 2025/03/05 21:30:46 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_lines(char *argv, t_data *data)
{
	char	*lines;
	int		fd;

	fd = open(argv, O_RDONLY);
	lines = get_next_line(fd);
	while (lines != NULL)
	{
		data->map_data->lines++;
		free(lines);
		lines = get_next_line(fd);
	}
	close(fd);
}

void	count_columns(char *argv, t_data *data)
{
	char	*lines;
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	lines = get_next_line(fd);
	i = 0;
	while (lines[i] != '\0' && lines[i] != '\n')
	{
		data->map_data->columns++;
		i++;
	}
	while (lines != NULL)
	{
		free(lines);
		lines = get_next_line(fd);
	}
	close(fd);
}

#include "so_long.h"

#include "so_long.h"

#include "so_long.h"

#include "so_long.h"

#include "so_long.h"

#include "so_long.h"

#include "so_long.h"

#include "so_long.h"

void	extract_from_fd_to_map(char *argv, t_data *data)
{
    int		i = 0, fd = open(argv, O_RDONLY);
    char	*lines;

    if (fd < 0)
        print_error_menssage("Failed to open file", data);
    data->map_data->map = ft_calloc(data->map_data->lines + 1, sizeof(char *));
    data->map_data->dummy_map = ft_calloc(data->map_data->lines + 1, sizeof(char *));
    if (!data->map_data->map || !data->map_data->dummy_map)
        print_error_menssage("Failed to allocate memory", data);
    while ((lines = get_next_line(fd)))
    {
        data->map_data->map[i] = ft_strdup(lines);
        data->map_data->dummy_map[i] = ft_strdup(lines);
        if (!data->map_data->map[i] || !data->map_data->dummy_map[i])
            print_error_menssage("Failed to duplicate line", data);
        free(lines);
        i++;
    }
    close(fd);
}


int	check_map_content(char **map)
{
	int	i;
	int	g;

	i = 0;
	while (map[i] != NULL)
	{
		g = 0;
		while (map[i][g] != '\0')
		{
			if (map [i][g] != '1' && map[i][g] != '0' && map[i][g] != 'P'
				&& map[i][g] != 'C' && map[i][g] != 'E' && map[i][g] != '\n')
				return (0);
			g++;
		}
		i++;
	}
	return (1);
}

int	check_map_components(char **map, t_data *data)
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
				data->content->player++;
			if (map[i][g] == 'C')
				data->content->collectible++;
			if (map[i][g] == 'E')
				data->content->exit++;
			g++;
		}
		i++;
	}
	if (data->content->player != 1 || data->content->collectible == 0
		|| data->content->exit != 1)
		return (0);
	return (1);
}
