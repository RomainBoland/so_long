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

#include "so_long_bonus.h"

int	init_textures(t_textures *tex)
{
	tex->floor = NULL;
	tex->wall = NULL;
	tex->player_right = NULL;
	tex->player_left = NULL;
	tex->flower_left = NULL;
	tex->flower_right = NULL;
	tex->enemy_angry_left = NULL;
	tex->enemy_angry_right = NULL;
	tex->enemy_idle_left = NULL;
	tex->enemy_idle_right = NULL;
	tex->duo_left = NULL;
	tex->duo_right = NULL;
	tex->collect = NULL;
	tex->exit = NULL;
	tex->exit_red = NULL;
	return (1);
}

int	handle_close(void *param)
{
	t_game	*game;

	if (param)
		game = (t_game *)param;
	else
		return (0);
	free_map_error(game->map);
	destroy_textures(game, game->tex);
	mlx_destroy_window(game->vars->mlx, game->vars->win);
	mlx_destroy_display(game->vars->mlx);
	free(game->vars->mlx);
	exit(0);
}

void	display_bold_message(t_game *game, char *msg, int x, int y)
{
	mlx_string_put(game->vars->mlx, game->vars->win, x - 1, y, 0xFFFFFF, msg);
	mlx_string_put(game->vars->mlx, game->vars->win, x + 1, y, 0xFFFFFF, msg);
	mlx_string_put(game->vars->mlx, game->vars->win, x, y - 1, 0xFFFFFF, msg);
	mlx_string_put(game->vars->mlx, game->vars->win, x, y + 1, 0xFFFFFF, msg);
	mlx_string_put(game->vars->mlx, game->vars->win, x, y, 0xFFFFFF, msg);
}

void	display_message(t_game *game)
{
	char	*collect;
	char	*msg;
	char	*temp;
	int		x;
	int		y;

	collect = ft_itoa(game->remaining);
	temp = ft_strjoin("Collect ", collect);
	msg = ft_strjoin(temp, " more items!");
	x = (game->map->width * TILE_SIZE) / 2 - 100;
	y = (game->map->height * TILE_SIZE) - 30;
	display_bold_message(game, msg, x, y);
	free(collect);
	free(temp);
	free(msg);
}

void	display_status(t_game *game)
{
	char	*moves_str;
	char	*collect_str;

	game->remaining = game->collectibles - game->collected;
	moves_str = ft_itoa(game->moves);
	collect_str = ft_itoa(game->remaining);
	display_bold_message(game, "Collectibles remaining: ", 10, 20);
	display_bold_message(game, collect_str, 200, 20);
	display_bold_message(game, "Moves: ", 10, 40);
	display_bold_message(game, moves_str, 70, 40);
	free(collect_str);
	free(moves_str);
}
