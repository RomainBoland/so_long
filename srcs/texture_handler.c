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

int handle_expose(t_game *game)
{
    render_game(game);
    return (0);
}

void render_game(t_game *game)
{
    int x;
    int y;
	
    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == '1')
                mlx_put_image_to_window(game->vars->mlx, game->vars->win,
                    game->tex->wall, x * 32, y * 32);
            else if (game->map->grid[y][x] == '0')
                mlx_put_image_to_window(game->vars->mlx, game->vars->win,
                    game->tex->floor, x * 32, y * 32);
            else if (game->map->grid[y][x] == 'C')
                mlx_put_image_to_window(game->vars->mlx, game->vars->win,
                    game->tex->collect, x * 32, y * 32);
            else if (game->map->grid[y][x] == 'E')
                mlx_put_image_to_window(game->vars->mlx, game->vars->win,
                    game->tex->exit, x * 32, y * 32);
            x++;
        }
        y++;
    }
    draw_player(game, game->map->start_x, game->map->start_y);
}

int load_textures(t_game *game, t_textures *tex)
{
    tex->floor = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/floor/wooden.xpm", &tex->width, &tex->height);
    if (!tex->floor)
    {
        printf("Failed to load floor texture\n");
        return (0);
    }
    printf("Floor texture loaded successfully\n");

    tex->wall = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/wall/wall.xpm", &tex->width, &tex->height);
    if (!tex->wall)
    {
        printf("Failed to load wall texture\n");
        return (0);
    }
    printf("Wall texture loaded successfully\n");

    tex->collect = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/collectible/collectible.xpm", &tex->width, &tex->height);
    if (!tex->collect)
    {
        printf("Failed to load collectible texture\n");
        return (0);
    }
    printf("Collectible texture loaded successfully\n");

    tex->exit = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/exit/exit.xpm", &tex->width, &tex->height);
    if (!tex->exit)
    {
        printf("Failed to load exit texture\n");
        return (0);
    }
    printf("Exit texture loaded successfully\n");

    return (load_player_sprites(game, &tex->player));
}