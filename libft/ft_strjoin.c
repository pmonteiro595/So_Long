/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:36:29 by pteixeir          #+#    #+#             */
/*   Updated: 2024/11/02 16:57:08 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*result;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = ft_calloc (sizeof(char), total_len + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy (result, s1, ft_strlen(s1) + 1);
	ft_strlcpy (&result[ft_strlen(result)], s2, ft_strlen(s2) + 1);
	return (result);
}
