/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:24:03 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 14:24:03 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_status(t_game *game)
{
	game->status.exit_flash = 0;
	game->status.current_message = NULL;
	game->status.message_time = 0;
}

int init_game(t_game *game, t_vars *vars, t_map *map, t_textures *tex)
{
    game->vars = vars;
    game->map = map;
	game->tex = tex;
	game->collected = 0;
    game->moves = 0;
    game->game_state = 0;
    game->last_frame = 0;

	init_status(game);
    vars->win = mlx_new_window(vars->mlx, map->width * TILE_SIZE, 
								map->height * TILE_SIZE, "so_long");
    if (!vars->win)
        return (0);
    return (1);
}

int init_mlx(t_vars *vars)
{
    vars->mlx = mlx_init();
    if (!vars->mlx)
        return (0);
    vars->win = mlx_new_window(vars->mlx, 800, 600, "so_long");
    if (!vars->win)
    {
        free(vars->mlx);
        return (0);
    }
    return (1);
}

int handle_expose(t_game *game)
{
    render_map(game);
	if (game->map->grid[game->map->start_y][game->map->start_x] == 'E' && 
        game->collected != game->collectibles)
		display_message(game, "Collect all items first!");
    return (0);
}

void set_hooks(t_vars *vars, t_game *game)
{
    mlx_hook(vars->win, 17, 0, handle_close, vars);  // Close window
    mlx_hook(vars->win, 2, 1L<<0, handle_keypress, game);  // Key press
    mlx_expose_hook(vars->win, handle_expose, game);  // Window expose
}
