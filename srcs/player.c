/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:57:29 by pteixeir          #+#    #+#             */
/*   Updated: 2025/02/12 22:44:44 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"

void load_player_sprites(t_player *player, void *mlx)
{
    int w;
    int h;

    player->img_standing_front = mlx_xpm_file_to_image(mlx, "sprites/Vegeta_standing_front.xpm", &w, &h);
    player->img_standing_back = mlx_xpm_file_to_image(mlx, "sprites/Vegeta_standing_back.xpm", &w, &h);
    player->img_moving_up = mlx_xpm_file_to_image(mlx, "sprites/Vegeta_moving_UP.xpm", &w, &h);
    player->img_moving_down = mlx_xpm_file_to_image(mlx, "sprites/Vegeta_moving_DOWN.xpm", &w, &h);
    player->img_moving_back = mlx_xpm_file_to_image(mlx, "sprites/moving_back_vegeta_nb.xpm", &w, &h);
    player->img_moving_front = mlx_xpm_file_to_image(mlx, "sprites/Vegeta_moving_front.xpm", &w, &h);
    player->img_catch_front = mlx_xpm_file_to_image(mlx, "sprites/Vegeta_catch_item_front_nb.xpm", &w, &h);
    player->img_catch_back = mlx_xpm_file_to_image(mlx, "sprites/Vegeta_catch_item_back_nb.xpm", &w, &h);
    player->img_transf[0] = mlx_xpm_file_to_image(mlx, "sprites/Vegeta_transf_ph1.xpm", &w, &h);
    player->img_transf[1] = mlx_xpm_file_to_image(mlx, "sprites/Vegeta_transf_ph2.xpm", &w, &h);
    player->img_transf[2] = mlx_xpm_file_to_image(mlx, "sprites/Vegeta_transf_ph3.xpm", &w, &h);
    player->current_img = player->img_standing_front;

}