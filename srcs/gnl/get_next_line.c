/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:25:34 by pteixeir          #+#    #+#             */
/*   Updated: 2025/01/11 03:00:15 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_stash(char *stash, int fd)
{
	char	*temp_buffer;
	int		bytes_read;

	temp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_char_in_str(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp_buffer);
			free(stash);
			return (NULL);
		}
		temp_buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, temp_buffer);
	}
	free(temp_buffer);
	return (stash);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	j = i;
	if (stash[i] == '\n')
		j++;
	line = ft_calloc(j + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_strcpy_gnl(stash, line, 1);
	return (line);
}

char	*ft_adjust_stash(char *stash)
{
	char	*new_stash;
	int		index;

	if (!stash)
		return (NULL);
	index = 0;
	while (stash[index] && stash[index] != '\n')
		index++;
	if (stash[index] == '\0')
	{
		free(stash);
		return (NULL);
	}
	index++;
	new_stash = ft_calloc(ft_strlen_gnl(stash + index) + 1, sizeof(char));
	if (!new_stash)
		return (NULL);
	ft_strcpy_gnl(stash + index, new_stash, 0);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_to_stash(stash, fd);
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	line = ft_extract_line(stash);
	stash = ft_adjust_stash(stash);
	return (line);
}
