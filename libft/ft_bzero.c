/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:57:05 by pteixeir          #+#    #+#             */
/*   Updated: 2025/02/06 23:04:43 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i++] = 0;
	}
}

/*
#include <stdio.h>

int main(void)
{
    char str[20] = "Hello, world!";

    printf("before ft_bzero: \"%s\"\n", str);

    ft_bzero(str, 5);

    printf("after ft_bzero: \"");
    for (int i = 0; i < 20; i++)
    {
        if (str[i] == '\0')
            printf("\\0");
        else
            printf("%c", str[i]);
    }
    printf("\"\n");

    return 0;
}
*/
