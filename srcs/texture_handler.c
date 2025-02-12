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

void render_map(t_game *game)
{
    mlx_clear_window(game->vars->mlx, game->vars->win);
    create_map_background(game);
    draw_game_objects(game);
}

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
