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

void	start_exit_flash(t_game *game, int new_x, int new_y)
{
	mlx_put_image_to_window(game->vars->mlx, game->vars->win,
		game->tex->exit_red, new_x * TILE_SIZE, new_y * TILE_SIZE);
}

int	load_textures2(t_game *game, t_textures *tex)
{
	tex->enemy_angry_left = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/ennemy/cali_angry_left.xpm", &tex->width, &tex->height);
	tex->enemy_angry_right = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/ennemy/cali_angry_right.xpm", &tex->width, &tex->height);
	tex->flower_left = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/player/flower_left.xpm", &tex->width, &tex->height);
	tex->flower_right = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/player/flower_right.xpm", &tex->width, &tex->height);
	tex->duo_left = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/player/duo_left.xpm", &tex->width, &tex->height);
	tex->duo_right = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/player/duo_right.xpm", &tex->width, &tex->height);
	tex->enemy_idle_left = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/ennemy/cali_idle_left.xpm", &tex->width, &tex->height);
	tex->enemy_idle_right = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/ennemy/cali_idle_right.xpm", &tex->width, &tex->height);
	if (!tex->enemy_angry_left || !tex->enemy_angry_right
		|| !tex->flower_left || !tex->flower_right
		|| !tex->duo_left || !tex->duo_right
		|| !tex->enemy_idle_left || !tex->enemy_idle_right)
		return (0);
	return (1);
}

int	load_basic_textures(t_game *game, t_textures *tex)
{
	tex->floor = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/floor/wooden.xpm", &tex->width, &tex->height);
	tex->wall = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/wall/wall.xpm", &tex->width, &tex->height);
	tex->player_right = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/player/player_right.xpm", &tex->width, &tex->height);
	if (!tex->floor || !tex->wall || !tex->player_right)
		return (0);
	return (1);
}

int	load_extra_textures(t_game *game, t_textures *tex)
{
	tex->player_left = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/player/player_left.xpm", &tex->width, &tex->height);
	if (!tex->player_left)
		return (0);
	tex->collect = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/collectible/collectible.xpm", &tex->width, &tex->height);
	if (!tex->collect)
		return (0);
	tex->exit = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/exit/exit.xpm", &tex->width, &tex->height);
	if (!tex->exit)
		return (0);
	tex->exit_red = mlx_xpm_file_to_image(game->vars->mlx,
			"sprites/exit/exit_red.xpm", &tex->width, &tex->height);
	if (!tex->exit_red)
		return (0);
	return (1);
}

int	load_textures(t_game *game, t_textures *tex)
{
	init_textures(tex);
	if (!load_basic_textures(game, tex))
	{
		ft_printf("Failed to load basic textures\n");
		return (0);
	}
	if (!load_extra_textures(game, tex))
	{
		ft_printf("Failed to load extra textures\n");
		return (0);
	}
	if (!load_textures2(game, tex))
	{
		ft_printf("Failed to load textures2\n");
		return (0);
	}
	return (1);
}
