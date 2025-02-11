/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:10:20 by pteixeir          #+#    #+#             */
/*   Updated: 2024/11/06 13:19:04 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bg, const char *ltl, size_t len)
{
	size_t	i;
	size_t	ltl_len;

	i = 0;
	ltl_len = ft_strlen(ltl);
	if (*ltl == '\0')
		return ((char *)bg);
	while (bg[i] != '\0' && i < len)
	{
		if (i + ltl_len <= len && ft_strncmp(&bg[i], ltl, ltl_len) == 0)
			return ((char *)&bg[i]);
		i++;
	}
	return (NULL);
}
