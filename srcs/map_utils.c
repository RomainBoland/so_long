/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:59:27 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 13:59:27 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player_pos(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->grid[i][j] == 'P')
			{
				map->start_x = j;
				map->start_y = i;
				return (1);
			}
		}
	}
	return (0);
}

int	check_map_walls(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width)
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (0);
	i = -1;
	while (++i < map->height)
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (0);
	return (1);
}

int	check_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->collectibles = 0;
	map->start_x = -1;
	map->start_y = -1;
	map->exit_x = -1;
	map->exit_y = -1;
	map->player_count = 0;
	map->exit_count = 0;
}
