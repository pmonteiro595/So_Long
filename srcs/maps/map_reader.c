/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:04:58 by pteixeir          #+#    #+#             */
/*   Updated: 2025/02/08 03:54:33 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
#include "libft.h"

char *get_next_line(int fd);

void free_map(char **map)
{
    int	i;
	
	i = 0;
	while (map[i])
	{
		ft_free(map[i]);
		i++;
	}
	ft_free(map);
}
/// @brief 
/// @param filename 
/// @return 
char **read_map(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("failed to open file");
		exit(EXIT_FAILURE);
	}
	char	**map = NULL;
	int	line_count = 0;
	char	*line;
	
	while ((line = get_next_line(fd)) != NULL)
	{
		char **tmp = ft_realloc(map, sizeof(char*) * (line_count + 2));
		if (!tmp) { perror("Allocation Error"); exit(EXIT_FAILURE); }
		map = tmp;
		map[line_count] = line;
		line_count++;
	}
	if(map)
		map[line_count] = NULL;
	close(fd);
	return (map);
}
