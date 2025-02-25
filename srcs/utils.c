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

int handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->map && game->map->grid)
		free_map(game->map);
	destroy_textures(game, game->tex);
    mlx_destroy_window(game->vars->mlx, game->vars->win);
    mlx_destroy_display(game->vars->mlx);
    free(game->vars->mlx);
    exit(0);
}

void display_status(t_game *game)
{
	char    *moves_str;
	
	moves_str = ft_itoa(game->moves);
	ft_printf("Moves : %s\n", moves_str);
	free(moves_str);
}
