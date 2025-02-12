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

#include "so_long.h"

void render_map(t_game *game)
{
    mlx_clear_window(game->vars->mlx, game->vars->win);
    create_map_background(game);
    draw_game_objects(game);
}

void draw_player(t_game *game, int x, int y)
{
    void *sprite;

    // Explicitly draw floor first
    mlx_put_image_to_window(game->vars->mlx, game->vars->win,
        game->tex->floor, x * TILE_SIZE, y * TILE_SIZE);

    if (game->tex->player.is_moving)
    {
        if (game->tex->player.direction == RIGHT)
            sprite = game->tex->player.run_right[game->tex->player.current_frame];
        else
            sprite = game->tex->player.run_left[game->tex->player.current_frame];
    }
    else
    {
        if (game->tex->player.direction == RIGHT)
            sprite = game->tex->player.idle_right;
        else
            sprite = game->tex->player.idle_left;
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
                mlx_put_image_to_window(game->vars->mlx, game->vars->win,
                    game->tex->collect, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map->grid[y][x] == 'E')
                mlx_put_image_to_window(game->vars->mlx, game->vars->win,
                    game->tex->exit, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map->grid[y][x] == 'P')
                draw_player(game, x, y);
            x++;
        }
        y++;
    }
}
