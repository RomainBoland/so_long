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

int handle_keypress(int keysym, t_game *game)
{
    int moved;

    moved = 0;
    if (keysym == 65307)  // ESC
        handle_close(game->vars);
    else if (keysym == 119 || keysym == 65362)  // W or up arrow
        moved = move_player(game, 0, -1);
    else if (keysym == 115 || keysym == 65364)  // S or down arrow
        moved = move_player(game, 0, 1);
    else if (keysym == 97 || keysym == 65361)   // A or left arrow
        moved = move_player(game, -1, 0);
    else if (keysym == 100 || keysym == 65363)  // D or right arrow
        moved = move_player(game, 1, 0);
	else if (keysym == 114)
	{
		//handle flower (animation with flower_left/right + change enemy state if less than 1 tile away)
		moved = 1;
		game->enemy.state = ENMEMY_IDLE;
	}
    if (moved)
        render_map(game);
    return (0);
}

int move_player(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;

    new_x = game->map->start_x + dx;
    new_y = game->map->start_y + dy;
    if (game->map->grid[new_y][new_x] == '1')
		return (0);
	if (dx < 0)
		game->player_direction = LEFT;
    else if (dx > 0)
		game->player_direction = RIGHT;
	if (game->map->grid[new_y][new_x] == 'E' && 
		game->collected != game->collectibles)
	{
		start_exit_flash(game, new_x, new_y);
		display_message(game);
		return (0);
	}
	if (game->map->grid[new_y][new_x] == 'X' &&
		game->enemy.state == 0)
	{
		ft_printf("You died... Have you tried pressing r next to Caliwooo ?\n");
		handle_close(game->vars);
	}
	if (check_win_condition(game, new_x, new_y))
		handle_close(game->vars);
    if (game->map->grid[new_y][new_x] == 'C')
		game->collected++;
    game->map->grid[game->map->start_y][game->map->start_x] = '0';
    game->map->start_x = new_x;
    game->map->start_y = new_y;
    game->map->grid[new_y][new_x] = 'P';
    game->moves++;
    return (1);
}
