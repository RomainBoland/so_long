/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:58:52 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 13:58:52 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_line_width(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	return (len);
}

int	count_height(int fd)
{
	char	*line;
	int		height;

	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (height);
}

int	read_map_size(char *filename, t_map *map)
{
	int		fd;
	char	*first_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	first_line = get_next_line(fd);
	if (!first_line)
		return (0);
	map->width = get_line_width(first_line);
	free(first_line);
	map->height = count_height(fd) + 1;
	close(fd);
	return (1);
}

int	allocate_map_grid(t_map *map)
{
	int	i;

	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = malloc(sizeof(char) * (map->width + 1));
		if (!map->grid[i])
			return (0);
		i++;
	}
	map->grid[map->height] = NULL;
	return (1);
}

int	read_map_content(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line && i < map->height)
	{
		ft_strlcpy(map->grid[i], line, map->width + 1);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
