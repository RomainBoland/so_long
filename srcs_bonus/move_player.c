/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:40:37 by rboland           #+#    #+#             */
/*   Updated: 2025/02/13 09:40:37 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_idle_enemy(t_game *game, int new_x, int new_y)
{
	if (new_x == game->enemy.x && new_y == game->enemy.y
		&& game->enemy.state == ENEMY_IDLE)
	{
		game->duo_mode = 1;
		game->enemy.x = -1;
		game->enemy.y = -1;
		if (game->flower_active == 1)
			game->flower_active = 0;
	}
}

int	check_collision(t_game *game, int new_x, int new_y)
{
	if (game->map->grid[new_y][new_x] == 'E'
		&& game->collected != game->collectibles)
	{
		start_exit_flash(game, new_x, new_y);
		display_message(game);
		return (0);
	}
	if (game->map->grid[new_y][new_x] == 'X'
		&& game->enemy.state == ENEMY_ANGRY)
	{
		ft_printf("You died... Have you tried pressing r next to her ?\n");
		handle_close(game);
	}
	return (1);
}

void	update_position(t_game *game, int new_x, int new_y)
{
	if (game->map->grid[new_y][new_x] == 'C')
		game->collected++;
	game->map->grid[game->map->start_y][game->map->start_x] = '0';
	game->map->start_x = new_x;
	game->map->start_y = new_y;
	game->map->grid[new_y][new_x] = 'P';
	game->moves++;
}

void	set_direction(t_game *game, int dx)
{
	if (dx < 0)
		game->player_direction = LEFT;
	else if (dx > 0)
		game->player_direction = RIGHT;
}

int	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map->start_x + dx;
	new_y = game->map->start_y + dy;
	if (game->map->grid[new_y][new_x] == '1')
		return (0);
	set_direction(game, dx);
	handle_idle_enemy(game, new_x, new_y);
	if (!check_collision(game, new_x, new_y))
		return (0);
	if (check_win_condition(game, new_x, new_y))
		handle_close(game);
	update_position(game, new_x, new_y);
	return (1);
}
