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
    if (!tex->floor)
        return (0);
    tex->wall = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/wall/wall.xpm", &tex->width, &tex->height);
    if (!tex->wall)
        return (0);
    tex->collect = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/collectible/collectible.xpm", &tex->width, &tex->height);
    if (!tex->collect)
        return (0);
    tex->exit = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/exit/exit.xpm", &tex->width, &tex->height);
    if (!tex->exit)
        return (0);
    return (load_player_sprites(game, &tex->player));
}
