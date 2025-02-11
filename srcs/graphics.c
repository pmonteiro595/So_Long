/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:57:19 by pteixeir          #+#    #+#             */
/*   Updated: 2025/02/06 19:54:07 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void    *mlx_ptr;
void    *win_ptr;
int	win_width = 800;
int	win_height = 600;

void init_window(char *filename)
{
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, win_width, win_height, "so_long");
	void *wall_img = mlx_xpm_file_to_image(mlx_ptr, "wall.xpm", &win_width, &win_height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, wall_img, 0, 0);
	mlx_loop(mlx_ptr);
}