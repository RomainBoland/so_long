/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:08:43 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 14:08:43 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(t_map *map, int x, int y, char **visited)
{
    if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
    if (map->grid[y][x] == '1' || visited[y][x] == '1')
		return ;
    visited[y][x] = '1';
    flood_fill(map, x + 1, y, visited);
    flood_fill(map, x - 1, y, visited);
    flood_fill(map, x, y + 1, visited);
    flood_fill(map, x, y - 1, visited);
}

int check_path(t_map *map)
{
    char    **visited;
    int     i;
    int     valid;

    visited = malloc(sizeof(char *) * map->height);
    if (!visited)
        return (0);
    i = -1;
    while (++i < map->height)
    {
        visited[i] = ft_calloc(map->width, sizeof(char));
        if (!visited[i])
            return (0);
    }
    flood_fill(map, map->start_x, map->start_y, visited);
    valid = is_path_valid(map, visited);
    free_visited(visited, map->height);
    return (valid);
}


void free_visited(char **visited, int height)
{
    int i;

    i = 0;
    while (i < height)
        free(visited[i++]);
    free(visited);
}

int is_path_valid(t_map *map, char **visited)
{
    int i;
    int j;

    i = -1;
    while (++i < map->height)
    {
        j = -1;
        while (++j < map->width)
        {
            if (map->grid[i][j] == 'C' && !visited[i][j])
                return (0);
            if (map->grid[i][j] == 'E' && !visited[i][j])
			    return (0);
        }
    }
    return (1);
}
