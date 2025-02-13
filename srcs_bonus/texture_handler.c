/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:34:13 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 15:34:13 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void start_exit_flash(t_game *game, int new_x, int new_y)
{
    mlx_put_image_to_window(game->vars->mlx, game->vars->win,
		game->tex->exit_red, new_x * TILE_SIZE, new_y * TILE_SIZE);
}

int load_textures(t_game *game, t_textures *tex)
{
    tex->floor = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/floor/wooden.xpm", &tex->width, &tex->height);
    tex->wall = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/wall/wall.xpm", &tex->width, &tex->height);
    tex->player = mlx_xpm_file_to_image(game->vars->mlx,
        "sprites/player/player_right.xpm", &tex->width, &tex->height);
    tex->collect = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/collectible/collectible.xpm", &tex->width, &tex->height);
    tex->exit = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/exit/exit.xpm", &tex->width, &tex->height);
	tex->exit_red = mlx_xpm_file_to_image(game->vars->mlx, 
		"sprites/exit/exit_red.xpm", &tex->width, &tex->height);

    if (!tex->floor || !tex->wall || !tex->player || 
        !tex->collect || !tex->exit)
        return (0);
    return (1);
}
