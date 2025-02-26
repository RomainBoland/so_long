/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:21:54 by rboland           #+#    #+#             */
/*   Updated: 2025/02/13 12:21:54 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <time.h>

# define TILE_SIZE 64
# define LEFT 0
# define RIGHT 1
# define ENEMY_ANGRY 0
# define ENEMY_IDLE 1

typedef struct s_enemy
{
	int	x;
	int	y;
	int	state;
	int	direction;
}	t_enemy;

typedef struct s_status
{
	int		exit_flash;
	char	*current_message;
	int		message_time;
}	t_status;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		start_x;
	int		start_y;
	int		exit_x;
	int		exit_y;
	int		player_count;
	int		exit_count;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_textures
{
	void	*floor;
	void	*wall;
	void	*player_right;
	void	*player_left;
	void	*flower_left;
	void	*flower_right;
	void	*enemy_angry_left;
	void	*enemy_angry_right;
	void	*enemy_idle_left;
	void	*enemy_idle_right;
	void	*duo_left;
	void	*duo_right;
	void	*collect;
	void	*exit;
	void	*exit_red;
	int		width;
	int		height;
}	t_textures;

typedef struct s_game
{
	t_vars		*vars;
	t_map		*map;
	t_textures	*tex;
	t_status	status;
	t_enemy		enemy;
	int			duo_mode;
	int			player_direction;
	int			remaining;
	int			collectibles;
	int			collected;
	int			moves;
	int			flower_active;
	int			flower_start;
}	t_game;

// game.c
int		check_win_condition(t_game *game, int new_x, int new_y);
int		handle_keypress(int keysym, t_game *game);

// init_game.c
void	init_status(t_game *game);
int		handle_expose(t_game *game);
int		init_game(t_game *game, t_vars *vars, t_map *map, t_textures *tex);
int		init_mlx(t_vars *vars);
void	set_hooks(t_vars *vars, t_game *game);

// map_parser.c
int		check_map_elements(t_map *map, t_game *game);
int		get_map_error(char *filename, t_map *map, t_game *game);
void	error_map(t_map *map, char *message);

// map_path.c
void	flood_fill(t_map *map, int x, int y, char **visited);
int		check_path(t_map *map);
void	free_visited(char **visited, int height);
int		is_path_valid(t_map *map, char **visited);

// map_read.c
int		get_line_width(char *line);
int		count_height(int fd);
int		read_map_size(char *filename, t_map *map);
int		allocate_map_grid(t_map *map);
int		read_map_content(char *filename, t_map *map);

// map_utils.c
int		check_map_walls(t_map *map);
int		check_file_extension(char *filename);
void	init_map(t_map *map);
int		find_player_pos(t_map *map);

// map_validation.c
int		validate_line_width(char *line, int expected_width);
int		check_map_shape(char *filename, t_map *map);
int		is_valid_char(char c);
int		check_map_chars(t_map *map);
void	free_map_error(t_map *map);

// enemy.c
void	init_enemy(t_game *game);
int		find_enemy_pos(t_game *game);

// move_player.c
void	handle_idle_enemy(t_game *game, int new_x, int new_y);
int		check_collision(t_game *game, int new_x, int new_y);
void	update_position(t_game *game, int new_x, int new_y);
void	set_direction(t_game *game, int dx);
int		move_player(t_game *game, int dx, int dy);

// texture_handler.c
void	start_exit_flash(t_game *game, int new_x, int new_y);
int		load_textures(t_game *game, t_textures *tex);

// render.c
void	draw_enemy(t_game *game);
void	draw_game_objects(t_game *game);
void	create_map_background(t_game *game);
void	render_map(t_game *game);

// render_player.c
void	*get_direction_sprite(t_game *game, void *right, void *left);
void	*get_player_sprite(t_game *game);
void	draw_player(t_game *game, int x, int y);

// handle_flower.c
void	handle_flower(t_game *game);
int		is_adjacent(int dx, int dy);

// utils.c
int		init_textures(t_textures *tex);
void	display_bold_message(t_game *game, char *msg, int x, int y);
int		handle_close(void *param);
void	display_message(t_game *game);
void	display_status(t_game *game);

// destroy_textures.c
void	destroy_enemy_textures(void *mlx, t_textures *tex);
void	destroy_player_textures(void *mlx, t_textures *tex);
void	destroy_env_textures(void *mlx, t_textures *tex);
void	destroy_textures(t_game *game, t_textures *tex);

#endif