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

int get_map_error(char *filename, t_map *map)
{
    init_map(map);
    if (!check_file_extension(filename))
        error_map(map, "Not a .ber file");
    if (!read_map_size(filename, map))
        error_map(map, "Failed to read map");
    if (!allocate_map_grid(map))
        error_map(map, "Memory allocation failed");
    if (!read_map_content(filename, map))
        error_map(map, "Invalid map content");
    if (!check_map_chars(map))
        error_map(map, "Invalid characters in map");
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
