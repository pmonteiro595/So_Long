/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:54:32 by pteixeir          #+#    #+#             */
/*   Updated: 2024/11/06 14:43:52 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str_calloc;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	str_calloc = ft_calloc (ft_strlen(s) + 1, sizeof(char));
	if (str_calloc == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str_calloc[i] = (*f)(i, s[i]);
		i++;
	}
	return (str_calloc);
}
