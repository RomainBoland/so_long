/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:14:13 by rboland           #+#    #+#             */
/*   Updated: 2025/02/12 22:01:29 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <fcntl.h>

#define TILE_SIZE 64

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


typedef struct s_textures {
    void    *floor;
    void    *wall;
    void    *player;    // Now just one sprite
    void    *collect;
    void    *exit;
    int     width;
    int     height;
} t_textures;

typedef struct s_game {
    t_vars      *vars;
    t_map       *map;
	t_textures  *tex;
	int			collectibles;
    int         collected;
    int         moves;
    int         game_state; // 0: intro, 1: playing, 2: won
    long        last_frame; // For timing
} t_game;

typedef struct s_tile_size {
    int     width;
    int     height;
} t_tile_size;

// game.c
int handle_keypress(int keysym, t_game *game);
int move_player(t_game *game, int dx, int dy);
int draw_intro(t_game *game);

// init_game.c
int handle_expose(t_game *game);
int init_game(t_game *game, t_vars *vars, t_map *map, t_textures *tex);
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
int load_textures(t_game *game, t_textures *tex);

//render.c
void draw_player(t_game *game, int x, int y);
void draw_game_objects(t_game *game);
void create_map_background(t_game *game);
void render_map(t_game *game);

// utils.c
int handle_close(t_vars *vars);

#endif