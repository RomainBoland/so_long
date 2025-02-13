/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:04:20 by rboland           #+#    #+#             */
/*   Updated: 2025/02/06 14:04:20 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_close(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    exit(0);
}
void display_message(t_game *game)
{
    char    *collect;
    char    *msg;
    int     x;
    int     y;

    collect = ft_itoa(game->remaining);
    msg = ft_strjoin("Collect ", collect);
    msg = ft_strjoin(msg, " more items!");
    
    x = (game->map->width * TILE_SIZE) / 2 - 100;
    y = (game->map->height * TILE_SIZE) - 30;
    mlx_string_put(game->vars->mlx, game->vars->win,
        x, y, 0xFFFFFF, msg);
    free(collect);
    free(msg);
}

void display_status(t_game *game)
{
    char	*moves_str;
    char	*collect_str;

    game->remaining = game->collectibles - game->collected;
	collect_str = ft_itoa(game->remaining);
    moves_str = ft_itoa(game->moves);
    
    mlx_string_put(game->vars->mlx, game->vars->win, 
        10, 20, 0xFF0000, "Collectibles remaining: ");
    mlx_string_put(game->vars->mlx, game->vars->win, 
        200, 20, 0xFFFF00, collect_str);
    
    mlx_string_put(game->vars->mlx, game->vars->win, 
        10, 40, 0xFF0000, "Moves: ");
    mlx_string_put(game->vars->mlx, game->vars->win, 
        70, 40, 0xFFFF00, moves_str);
    
    free(collect_str);
    free(moves_str);
}
