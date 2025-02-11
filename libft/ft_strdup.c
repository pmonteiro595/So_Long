/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:36:08 by pteixeir          #+#    #+#             */
/*   Updated: 2024/11/06 14:31:59 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str_mlc;
	size_t	size_of_s;
	size_t	i;

	i = 0;
	size_of_s = (ft_strlen (s));
	str_mlc = malloc (sizeof(char) * size_of_s + (1));
	if (str_mlc == NULL)
		return (NULL);
	while (i <= size_of_s)
	{
		str_mlc[i] = s[i];
		i++;
	}
	return (str_mlc);
}
