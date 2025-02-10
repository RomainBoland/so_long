/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:14:13 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 14:29:15 by rboland          ###   ########.fr       */
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

// init_game.c
int init_mlx(t_vars *vars);
void set_hooks(t_vars *vars);

// map_parser.c
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

// map_validation.c
int	is_valid_char(char c);
int	check_map_chars(t_map *map);
void	free_map(t_map *map);

// map_walls.c
// render.c
// utils.c
int handle_close(t_vars *vars);
int handle_keypress(int keysym, t_vars *vars);


#endif