/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:32:12 by pteixeir          #+#    #+#             */
/*   Updated: 2024/11/06 13:27:04 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;
	size_t			i;
	size_t			total_size;

	total_size = nmemb * size;
	i = 0;
	res = malloc(total_size);
	if (res == NULL)
		return (NULL);
	while (i < total_size)
	{
		res[i++] = '\0';
	}
	return (res);
}
