/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:14:13 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 15:48:21 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <fcntl.h>

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
    void    *mlx;
    void    *win;
}   t_vars;

typedef struct s_anim {
    void    *frames[4];     // Array for walking animation frames
    int     current_frame;  // Current frame index
    int     frame_count;    // Total number of frames
    int     frame_delay;    // Delay between frames
} t_anim;

typedef struct s_player {
    float   x;          // Actual position (for smooth movement)
    float   y;
    int     tile_x;     // Target tile position
    int     tile_y;
    float   move_speed; // For smooth movement
    t_anim  anim;       // Animation data
} t_player;

typedef struct s_textures {
    void    *floor;
    int     width;  // texture width
    int     height; // texture height
} t_textures;

typedef struct s_game {
    t_vars      *vars;
    t_map       *map;
	t_textures  *tex;
    t_player    player;
    int         collectibles;
    int         moves;
    int         game_state; // 0: intro, 1: playing, 2: won
    long        last_frame; // For timing
} t_game;

typedef struct s_tile_size {
    int     width;
    int     height;
} t_tile_size;

// init_game.c
int init_game(t_game *game, t_vars *vars, t_map *map);
int init_mlx(t_vars *vars);
void set_hooks(t_vars *vars, t_game *game);

// map_parser.c
int check_map_elements(t_map *map);
int get_map_error(char *filename, t_map *map);
void error_map(t_map *map, char *message);

// map_path.c
void flood_fill(t_map *map, int x, int y, char **visited);
int check_path(t_map *map);
void free_visited(char **visited, int height);
int is_path_valid(t_map *map, char **visited);

// map_read.c
int get_line_width(char *line);
int count_height(int fd);
int	read_map_size(char *filename, t_map *map);
int allocate_map_grid(t_map *map);
int	read_map_content(char *filename, t_map *map);

// map_utils.c
int check_map_walls(t_map *map);
int check_file_extension(char *filename);
void	init_map(t_map *map);
int find_player_pos(t_map *map);

// map_validation.c
int	is_valid_char(char c);
int	check_map_chars(t_map *map);
void	free_map(t_map *map);

// texture_handler.c
t_tile_size get_tile_size(t_game *game, int win_width, int win_height);
int handle_expose(t_game *game);
void draw_map(t_game *game, t_textures *tex);
int load_textures(t_game *game, t_textures *tex);

// utils.c
int handle_close(t_vars *vars);
int handle_keypress(int keysym, t_vars *vars);


#endif