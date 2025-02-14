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
