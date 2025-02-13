/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:04:17 by rboland           #+#    #+#             */
/*   Updated: 2025/02/06 14:04:17 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_win_condition(t_game *game, int new_x, int new_y)
{
	if (game->map->grid[new_y][new_x] == 'E' &&
		game->collected == game->collectibles)
		return (1);
	return (0);
}

int draw_intro(t_game *game)
{
    static float alpha = 0;
    char *message = "Welcome to so_long";
    
    mlx_clear_window(game->vars->mlx, game->vars->win);
    mlx_string_put(game->vars->mlx, game->vars->win, 
                   400, 300, 0xFFFFFF - (int)(alpha * 255), message);
    alpha += 0.01;
    if (alpha >= 1)
        game->game_state = 1;
    return (0);
}
