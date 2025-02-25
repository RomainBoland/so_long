/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:52:49 by rboland           #+#    #+#             */
/*   Updated: 2025/02/25 13:52:49 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void destroy_enemy_textures(void *mlx, t_textures *tex)
{
    if (tex->enemy_angry_left)
        mlx_destroy_image(mlx, tex->enemy_angry_left);
    if (tex->enemy_angry_right)
        mlx_destroy_image(mlx, tex->enemy_angry_right);
    if (tex->enemy_idle_left)
        mlx_destroy_image(mlx, tex->enemy_idle_left);
    if (tex->enemy_idle_right)
        mlx_destroy_image(mlx, tex->enemy_idle_right);
}

void destroy_player_textures(void *mlx, t_textures *tex)
{
    if (tex->player_right)
        mlx_destroy_image(mlx, tex->player_right);
    if (tex->player_left)
        mlx_destroy_image(mlx, tex->player_left);
    if (tex->flower_left)
        mlx_destroy_image(mlx, tex->flower_left);
    if (tex->flower_right)
        mlx_destroy_image(mlx, tex->flower_right);
    if (tex->duo_left)
        mlx_destroy_image(mlx, tex->duo_left);
    if (tex->duo_right)
        mlx_destroy_image(mlx, tex->duo_right);
}

void destroy_env_textures(void *mlx, t_textures *tex)
{
    if (tex->floor)
        mlx_destroy_image(mlx, tex->floor);
    if (tex->wall)
        mlx_destroy_image(mlx, tex->wall);
    if (tex->collect)
        mlx_destroy_image(mlx, tex->collect);
    if (tex->exit)
        mlx_destroy_image(mlx, tex->exit);
    if (tex->exit_red)
        mlx_destroy_image(mlx, tex->exit_red);
}

void destroy_textures(t_game *game, t_textures *tex)
{
    void *mlx;

    mlx = game->vars->mlx;
    destroy_enemy_textures(mlx, tex);
    destroy_player_textures(mlx, tex);
    destroy_env_textures(mlx, tex);
}
