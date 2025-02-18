/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:11:58 by pteixeir          #+#    #+#             */
/*   Updated: 2025/02/12 23:01:35 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"
#include "so_long.h"

int main(int argc, char**argv)
{
    if (argc != 2)
    {
        write(1, "Usage: ./so_long <map_file>\n", 26);
        return (1);
    }
    char **map = read_map(argv[1]);
    init_window(argv[1]);

    return (0);
}
