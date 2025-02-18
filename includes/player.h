/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:33:14 by pteixeir          #+#    #+#             */
/*   Updated: 2025/02/12 22:47:42 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "so_long.h"

typedef struct s_player
{
    void    *img_standing_front;
    void	*img_standing_back;
	void	*img_moving_up;
	void	*img_moving_down;
	void	*img_moving_back;
	void	*img_moving_front;
	void	*img_catch_front;
	void	*img_catch_back;
	void	*img_transf[3];
	void	*current_img;
	int	x;
	int	y;
	int	frame;
}	t_player;

void	load_player_sprites(t_player *player, void *mlx);
void	set_player_sprite(t_player *player, char direction);
void	transform_to_ssj(t_player *player);

#endif
