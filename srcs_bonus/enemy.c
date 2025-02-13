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
    game->enemy.x = -1;
    game->enemy.y = -1;
    game->enemy.state = ENEMY_ANGRY;    // Add ENEMY_ANGRY define to your header
    game->enemy.direction = RIGHT;      // Default direction
}

void find_enemy_pos(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == 'X')
            {
                game->enemy.x = x;
                game->enemy.y = y;
                return;
            }
            x++;
        }
        y++;
    }
}
