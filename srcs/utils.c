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
void display_message(t_game *game, char *msg)
{
    // Display message at top of window
    mlx_string_put(game->vars->mlx, game->vars->win, 
        10, 20, 0xFFFFFF, msg);
}

void display_status(t_game *game)
{
    char *collect_str;
    char *moves_str;
    
    collect_str = ft_itoa(game->collectibles - game->collected);
    moves_str = ft_itoa(game->moves);
    
    mlx_string_put(game->vars->mlx, game->vars->win, 
        10, 20, 0xFFFFFF, "Collectibles remaining: ");
    mlx_string_put(game->vars->mlx, game->vars->win, 
        200, 20, 0xFFFF00, collect_str);
    
    mlx_string_put(game->vars->mlx, game->vars->win, 
        10, 40, 0xFFFFFF, "Moves: ");
    mlx_string_put(game->vars->mlx, game->vars->win, 
        70, 40, 0xFFFF00, moves_str);
    
    free(collect_str);
    free(moves_str);
}
