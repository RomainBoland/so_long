/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:51:43 by rboland           #+#    #+#             */
/*   Updated: 2025/02/13 23:51:43 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void init_enemy(t_game *game)
{
    // printf("Initializing enemy...\n");
    game->enemy.x = -1;
    game->enemy.y = -1;
    game->enemy.state = ENEMY_ANGRY;
    game->enemy.direction = RIGHT;
    // printf("Enemy initialized: pos=(%d,%d), state=%d, dir=%d\n",
    //     game->enemy.x, game->enemy.y, game->enemy.state, game->enemy.direction);
}

int find_enemy_pos(t_game *game)
{
    int x;
    int y;
	int	found;

    y = 0;
	found = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == 'X')
            {
				if (found == 1)
					return (0);
				found++;
                game->enemy.x = x;
                game->enemy.y = y;
            }
            x++;
        }
        y++;
    }
	return (1);
}
