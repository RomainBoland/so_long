/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:43:25 by rboland           #+#    #+#             */
/*   Updated: 2025/02/14 01:43:25 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_adjacent(t_game *game, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	
	(void)game;
	dx = abs(x1 - x2);
	dy = abs(y1 - y2);

	return (dx <= 1 && dy <= 1);
}

void	handle_flower(t_game *game)
{
	if (is_adjacent(game, game->map->start_x, game->map->start_y,
					game->enemy.x, game->enemy.y))
	{
		game->enemy.state = ENEMY_IDLE;
		printf("Enemy pacified !\n");
	}
	game->flower_active = 1;
	game->flower_start = time(NULL);
}
