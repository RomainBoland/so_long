/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:00:00 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 14:00:00 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int validate_line_width(char *line, int expected_width)
{
    int current_width;

    current_width = get_line_width(line);
    return (current_width == expected_width);
}

int check_map_shape(char *filename, t_map *map)
{
    int     fd;
    char    *line;
    int     expected_width;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    line = get_next_line(fd);
    if (!line)
        return (0);
    expected_width = map->width;
    free(line);
    while ((line = get_next_line(fd)))
    {
        if (!validate_line_width(line, expected_width))
        {
            free(line);
            return (0);
        }
        free(line);
    }
    close(fd);
    return (1);
}

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'P' || 
		c == 'E' || c == 'C' || c == '\n' || c == 'X')
		return (1);
	return (0);
}

int	check_map_chars(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (!is_valid_char(map->grid[i][j]))
				return (0);
		}
	}
	return (1);
}

void	free_map_error(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}
