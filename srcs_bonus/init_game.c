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

#include "so_long_bonus.h"

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
	game->remaining = 0;
    game->moves = 0;
	game->duo_mode = 0;
	game->player_direction = RIGHT;
	game->flower_active = 0;
	game->flower_start = 0;

    game->remaining = game->collectibles;
	init_enemy(game);
	if (!find_enemy_pos(game))
	{
		error_map(map, "More than one enemy has been found");
		return(0);
	}
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
    return (0);
}

void set_hooks(t_vars *vars, t_game *game)
{
	mlx_hook(vars->win, 17, 0, handle_close, game);
	mlx_hook(vars->win, 2, 1L<<0, handle_keypress, game);
    mlx_expose_hook(vars->win, handle_expose, game);
}
