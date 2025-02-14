/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:00:36 by rboland           #+#    #+#             */
/*   Updated: 2025/02/12 16:00:36 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void render_map(t_game *game)
{
    mlx_clear_window(game->vars->mlx, game->vars->win);
    create_map_background(game);
    draw_game_objects(game);
    display_status(game);
}

void draw_enemy(t_game *game)
{
    void    *sprite;

    if (game->enemy.x == -1 || game->enemy.y == -1)
		return;
    if (game->enemy.x > game->map->start_x)
    {
        game->enemy.direction = LEFT;
        if (game->enemy.state == 0)
            sprite = game->tex->enemy_angry_left;
        else if (game->enemy.state == 1)
            sprite = game->tex->enemy_idle_left;
    }
    else
    {
        game->enemy.direction = RIGHT;
        if (game->enemy.state == 0)
            sprite = game->tex->enemy_angry_right;
        else if (game->enemy.state == 1)
            sprite = game->tex->enemy_idle_right;
    }
    if (!sprite)
        return;
    mlx_put_image_to_window(game->vars->mlx, game->vars->win,
        sprite, game->enemy.x * TILE_SIZE, game->enemy.y * TILE_SIZE);
}

void draw_player(t_game *game, int x, int y)
{
    void *sprite;
    time_t current_time;

	printf("Flower active ? : %d\n", game->flower_active);
	printf("Enemy state ? : %d\n", game->enemy.state);
	printf("duo mode ? : %d\n", game->duo_mode);

	if (game->duo_mode)
	{
		if (game->player_direction == RIGHT) 
			sprite = game->tex->duo_right;
		else
			sprite = game->tex->duo_left;
	}
    else if (game->flower_active)
    {
        current_time = time(NULL);
        if (current_time - game->flower_start >= 1)
            game->flower_active = 0;
        else
        {
			if (game->player_direction == RIGHT)
				sprite = game->tex->flower_right;
			else
				sprite = game->tex->flower_left;
            mlx_put_image_to_window(game->vars->mlx, game->vars->win,
                sprite, x * TILE_SIZE, y * TILE_SIZE);
            return;
        }
    }
    else 
	{
		if (game->player_direction == RIGHT)
			sprite = game->tex->player_right;
		else
			sprite = game->tex->player_left;
	}
    mlx_put_image_to_window(game->vars->mlx, game->vars->win,
        sprite, x * TILE_SIZE, y * TILE_SIZE);
}

void create_map_background(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] != '1')
                mlx_put_image_to_window(game->vars->mlx, game->vars->win,
                    game->tex->floor, x * TILE_SIZE, y * TILE_SIZE);
            if (game->map->grid[y][x] == '1')
                mlx_put_image_to_window(game->vars->mlx, game->vars->win,
                    game->tex->wall, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

void draw_game_objects(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == 'C')
			{
				// printf("Trying to draw collectibles...\n");
                mlx_put_image_to_window(game->vars->mlx, game->vars->win,
                    game->tex->collect, x * TILE_SIZE, y * TILE_SIZE);
				// printf("Collectibles drawed !\n");
			}
            else if (game->map->grid[y][x] == 'E')
            { 
				// printf("Trying to draw exit\n");
				mlx_put_image_to_window(game->vars->mlx, game->vars->win,
                    game->tex->exit, x * TILE_SIZE, y * TILE_SIZE);
				// printf("exit Drawed !\n");
			}
            else if (game->map->grid[y][x] == 'P')
			{
				// printf("Trying to draw player\n");
                draw_player(game, x, y);
				// printf("player Drawed !\n");
			}
			else if (game->map->grid[y][x] == 'X')
			{
				// printf("Trying to draw enemy\n");
				draw_enemy(game);
				// printf("enemy Drawed !\n");
			}
			x++;
        }
        y++;
    }
}
