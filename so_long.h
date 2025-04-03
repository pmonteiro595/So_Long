/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:57:18 by pteixeir          #+#    #+#             */
/*   Updated: 2025/04/03 22:46:27 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define ESC 65307
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97
# define RIGHT_ARROW 65363
# define LEFT_ARROW 65361
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define STAND_RIGHT 0
# define STAND_LEFT 1
# define FLY_RIGHT 7
# define FLY_LEFT 6


typedef struct s_map_data
{
    int		lines;
    int		columns;
    int		player_position[2];
    int		exit_position[2];
    int		moves;
    int		collectibles;
    char	**map;
    char	**dummy_map;
}			t_map_data;

typedef struct s_content
{
    int		player;
    int		collectible;
    int		exit;
}			t_content;

typedef struct s_data
{
    t_map_data	*map_data;
    t_content	*content;
    void		*mlx;
    void		*win;
    void		*end_img;
    void		*end_win;
    void		**img;
    int			player_img_index;
	int			last_horizontal_dir;
}			t_data;

int		close_window(t_data *data);
int		check_dummy_map(char **map);
int		check_map_content(char **map);
int		check_file_is_empty(char *argv);
int		check_file_exist(char *filename);
int		check_file_extension(char *filename);
int		check_map_is_rectangular(char **map);
int		update_player_sprite(int keycode, t_data *data);
int		close_ending(int keycode, t_data *data);
int		check_map_components(char **map, t_data *data);
int		switch_to_main_window(int keycode, t_data *data);
int		check_map_enclosed_by_walls(char **map, t_data *data);
int		key_release(int keycode, t_data *data);


void	free_all(t_data *data);
void	check_file(char *argv);
void	check_map(t_data *data);
void	show_intro(t_data *data);
void	load_player_sprites(t_data *data);
void	show_end_image(t_data *data);
void	value_initialize(t_data **data);
void	graphics_initialize(t_data *data);
void	free_map_data(t_map_data *map_data);
void	count_lines(char *argv, t_data *data);
void	check_utils(char *argv, t_data *data);
void	count_columns(char *argv, t_data *data);
void	render_sprites(t_data *data, int i, int g);
void	move_player(int new_x, int new_y, t_data *data);
void	extract_from_fd_to_map(char *argv, t_data *data);
void	print_error_menssage(char *menssage, t_data *data);
void	flood_fill(char **map, int i, int g, t_data *data);
void	find_player_and_exit_position(char **map, t_data *data);
void	update_player_position(t_data *data, int new_x, int new_y);
void	check_exit_and_update(t_data *data, char new_pos);
void	count_collectibles(t_data *data);

#endif