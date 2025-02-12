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
    if (game->map->grid[new_y][new_x] == 'C')
		game->collected++;
	printf("Collected : %d\n", game->collected);
    game->map->grid[game->map->start_y][game->map->start_x] = '0';
    game->map->start_x = new_x;
    game->map->start_y = new_y;
    game->map->grid[new_y][new_x] = 'P';
    
    return (1);
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
