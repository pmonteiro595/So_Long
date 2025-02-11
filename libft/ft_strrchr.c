/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:37:22 by pteixeir          #+#    #+#             */
/*   Updated: 2024/11/02 16:57:22 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (const char)c)
			count++;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	i = 0;
	while (count > 0)
	{
		if (s[i] == (const char)c)
			count--;
		if (count == 0)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
