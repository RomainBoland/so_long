/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:14:13 by rboland           #+#    #+#             */
/*   Updated: 2025/02/12 16:03:07 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <fcntl.h>

#define TILE_SIZE 64
#define LEFT  0
#define RIGHT 1

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

typedef struct s_player_sprites {
    void    *run_right[6];    // 6 sprites for running right
    void    *run_left[6];     // 6 sprites for running left
    void    *idle_right;      // Standing still facing right
    void    *idle_left;       // Standing still facing left
    int     current_frame;     // Current animation frame (0-5)
    int     direction;        // LEFT or RIGHT
    int     is_moving;        // 0: idle, 1: running
} t_player_sprites;

typedef struct s_textures {
    void            *floor;
    void            *wall;
    void            *collect;
    void            *exit;
    t_player_sprites player;
    int             width;
    int             height;
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
int handle_expose(t_game *game);
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

// player_sprite.c
void free_player_sprites(t_game *game);
int load_player_run(t_game *game, void **sprites, char **paths);
int load_player_idle(t_game *game, t_player_sprites *player);
int load_player_sprites(t_game *game, t_player_sprites *player);

// texture_handler.c
int load_textures(t_game *game, t_textures *tex);

//render.c
void draw_player(t_game *game, int x, int y);
void draw_game_objects(t_game *game);
void create_map_background(t_game *game);
void render_map(t_game *game);

// utils.c
int handle_close(t_vars *vars);
int handle_keypress(int keysym, t_vars *vars);

#endif