/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:56:40 by pteixeir          #+#    #+#             */
/*   Updated: 2025/02/12 22:57:03 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"

void update_player_sprite(t_player *player, char direction)
{
    if (direction == 'W')
        player->current_img = player->img_moving_up;
    else if (direction == 'S')
        player->current_img = player->img_moving_down;
    else if (direction == 'A')
        player->current_img = player->img_moving_back;
    else if (direction == 'D')
        player->current_img = player->img_moving_front;
    else
        player->current_img = player->img_standing_front;
}

void transform_to_ssj(t_player *player)
{
    static int phase = 0;
    player->current_img = player->img_transf[phase++ % 3];
}
