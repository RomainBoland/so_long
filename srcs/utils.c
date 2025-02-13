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
void display_bold_message(t_game *game, char *msg, int x, int y, int color)
{
   mlx_string_put(game->vars->mlx, game->vars->win, x-1, y, color, msg);
   mlx_string_put(game->vars->mlx, game->vars->win, x+1, y, color, msg);
   mlx_string_put(game->vars->mlx, game->vars->win, x, y-1, color, msg);
   mlx_string_put(game->vars->mlx, game->vars->win, x, y+1, color, msg);
   mlx_string_put(game->vars->mlx, game->vars->win, x, y, color, msg);
}
void display_message(t_game *game)
{
    char    *collect;
    char    *msg;
    char    *temp;
	int		x;
    int		y;

    collect = ft_itoa(game->remaining);
    temp = ft_strjoin("Collect ", collect);
    msg = ft_strjoin(temp, " more items!");
	x = (game->map->width * TILE_SIZE) / 2 - 100;
    y = (game->map->height * TILE_SIZE) - 30;
    
    display_bold_message(game, msg, x, y, 0xFFFFFF);
    
    free(collect);
    free(temp);
    free(msg);
}

void display_status(t_game *game)
{
   char    *moves_str;
   char    *collect_str;

   game->remaining = game->collectibles - game->collected;
   collect_str = ft_itoa(game->remaining);
   moves_str = ft_itoa(game->moves);
   
   // Collectibles counter
   display_bold_message(game, "Collectibles remaining: ", 10, 20, 0xFFFFFF);
   display_bold_message(game, collect_str, 200, 20, 0xFFFF00);
   
   // Moves counter
   display_bold_message(game, "Moves: ", 10, 40, 0xFFFFFF);
   display_bold_message(game, moves_str, 70, 40, 0xFFFF00);
   
   free(collect_str);
   free(moves_str);
}
