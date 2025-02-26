/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:45:15 by rboland           #+#    #+#             */
/*   Updated: 2025/02/17 11:45:15 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_adjacent(int dx, int dy)
{
	return (dx <= 1 && dy <= 1);
}

void	handle_flower(t_game *game)
{
	int	dx;
	int	dy;

	dx = abs(game->map->start_x - game->enemy.x);
	dy = abs(game->map->start_y - game->enemy.y);
	if (is_adjacent(dx, dy))
	{
		game->enemy.state = ENEMY_IDLE;
		printf("Enemy pacified !\n");
	}
	game->flower_active = 1;
	game->flower_start = time(NULL);
}
