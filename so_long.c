/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:58:26 by pteixeir          #+#    #+#             */
/*   Updated: 2025/04/03 19:22:37 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data *data;

	if (argc != 2)
	{
		print_error_menssage("These are not the arguments you're looking for\n", NULL);
		return(1);
	}
	else
    {
        ft_putstr_fd("Debug: Checking file\n", 1);
        check_file(argv[1]);
        ft_putstr_fd("Debug: Initializing values\n", 1);
        value_initialize(&data);
        ft_putstr_fd("Debug: Checking utils\n", 1);
        check_utils(argv[1], data);
        ft_putstr_fd("Debug: Showing intro\n", 1);
        show_intro(data);
        ft_putstr_fd("Debug: Freeing all data\n", 1);
        free_all(data);
    }
    return (0);
}

void	value_initialize(t_data **data)
{
    *data = ft_calloc(sizeof(t_data), 1);
    if (!*data)
        print_error_menssage("Failed to allocate memory for data", NULL);

    (*data)->map_data = ft_calloc(sizeof(t_map_data), 1);
    if (!(*data)->map_data)
        print_error_menssage("Failed to allocate memory for map_data", *data);

    (*data)->content = ft_calloc(sizeof(t_content), 1);
    if (!(*data)->content)
        print_error_menssage("Failed to allocate memory for content", *data);

    (*data)->content->player = 0;
    (*data)->content->collectible = 0;
    (*data)->content->exit = 0;
    (*data)->map_data->lines = 0;
    (*data)->map_data->columns = 0;
    (*data)->map_data->map = NULL;
    (*data)->map_data->player_position[0] = 0;
    (*data)->map_data->player_position[1] = 0;
    (*data)->map_data->moves = 0;
}

void	print_error_menssage(char *menssage, t_data *data)
{
	ft_printf("Error\n%s ☜(꒡⌓꒡)\n", menssage);
	if (data != NULL)
		free_all(data);
	exit(1);
}

void	count_collectibles(t_data *data)
{
	int	x;
	int	y;
	int	count = 0;

	y = 0;
	while (data->map_data->map[y])
	{
		x = 0;
		while (data->map_data->map[y][x])
		{
			if (data->map_data->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	data->map_data->collectibles = count;
}
