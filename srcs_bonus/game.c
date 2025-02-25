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

#include "so_long_bonus.h"

int	check_win_condition(t_game *game, int new_x, int new_y)
{
	if (game->map->grid[new_y][new_x] == 'E' &&
		game->collected == game->collectibles)
		return (1);
	return (0);
}

int handle_keypress(int keysym, t_game *game)
{
    int moved;

    moved = 0;
    if (keysym == 65307)  // ESC
        handle_close(game);
    else if (keysym == 119 || keysym == 65362)
        moved = move_player(game, 0, -1);
    else if (keysym == 115 || keysym == 65364)
        moved = move_player(game, 0, 1);
    else if (keysym == 97 || keysym == 65361)
        moved = move_player(game, -1, 0);
    else if (keysym == 100 || keysym == 65363)
        moved = move_player(game, 1, 0);
	else if (keysym == 114)
	{
		handle_flower(game);
		render_map(game);
		return (0);
	}
    if (moved)
        render_map(game);
    return (0);
}
