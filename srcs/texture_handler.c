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

#include "so_long.h"

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

    if (!tex->floor || !tex->wall || !tex->player || 
        !tex->collect || !tex->exit)
        return (0);
    return (1);
}

void	destroy_textures(t_game *game, t_textures *tex)
{
	if (tex->player)
		mlx_destroy_image(game->vars->mlx, tex->player);
    if (tex->floor)
        mlx_destroy_image(game->vars->mlx, tex->floor);
    if (tex->wall)
        mlx_destroy_image(game->vars->mlx, tex->wall);
    if (tex->collect)
        mlx_destroy_image(game->vars->mlx, tex->collect);
    if (tex->exit)
        mlx_destroy_image(game->vars->mlx, tex->exit);
}
