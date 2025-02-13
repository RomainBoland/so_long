/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:00:28 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 14:00:28 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_elements(t_map *map, t_game *game)
{
    int i;
    int j;
    int p_count;
    int e_count;
    int c_count;

    p_count = 0;
    e_count = 0;
    c_count = 0;
    i = -1;
    while (++i < map->height)
    {
        j = -1;
        while (++j < map->width)
        {
            if (map->grid[i][j] == 'P')
                p_count++;
            if (map->grid[i][j] == 'E')
                e_count++;
            if (map->grid[i][j] == 'C')
                c_count++;
        }
    }
	game->collectibles = c_count;
    return (p_count == 1 && e_count == 1 && c_count > 0);
}

int get_map_error(char *filename, t_map *map, t_game *game)
{
    init_map(map);
    if (!check_file_extension(filename))
		error_map(map, "Not a .ber file");
    if (!read_map_size(filename, map))
		error_map(map, "Failed to read map");
	if (!check_map_shape(filename, map))
		error_map(map, "Map must be rectangular");
    if (!allocate_map_grid(map))
        error_map(map, "Memory allocation failed");
    if (!read_map_content(filename, map))
		error_map(map, "Invalid map content");
    if (!check_map_chars(map))
        error_map(map, "Invalid characters in map");
    if (!check_map_elements(map, game))
        error_map(map, "Map must have 1 player, 1 exit and at least 1 collectible");
    if (!find_player_pos(map))
        error_map(map, "Player position error");
    if (!check_map_walls(map))
        error_map(map, "Map must be surrounded by walls");
    if (!check_path(map))
        error_map(map, "No valid path exists");
    return (1);
}

void error_map(t_map *map, char *message)
{
    if (map && map->grid)
        free_map(map);
    ft_putstr_fd("Error:\n", 2);
    ft_putstr_fd(message, 2);
    ft_putstr_fd("\n", 2);
    exit(1);
}
