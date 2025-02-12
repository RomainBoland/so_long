/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:19:06 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 21:19:06 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_player_sprites(t_game *game)
{
    int i;

    i = 0;
    while (i < 6)
    {
        if (game->tex->player.run_right[i])
            mlx_destroy_image(game->vars->mlx, game->tex->player.run_right[i]);
        if (game->tex->player.run_left[i])
            mlx_destroy_image(game->vars->mlx, game->tex->player.run_left[i]);
        i++;
    }
    if (game->tex->player.idle_right)
        mlx_destroy_image(game->vars->mlx, game->tex->player.idle_right);
    if (game->tex->player.idle_left)
        mlx_destroy_image(game->vars->mlx, game->tex->player.idle_left);
}

int load_player_run(t_game *game, void **sprites, char **paths)
{
    int i;

    i = 0;
    while (i < 6)
    {
        sprites[i] = mlx_xpm_file_to_image(game->vars->mlx, 
            paths[i], &game->tex->width, &game->tex->height);
        if (!sprites[i])
            return (0);
        i++;
    }
    return (1);
}


int load_player_idle(t_game *game, t_player_sprites *player)
{
    player->idle_right = mlx_xpm_file_to_image(game->vars->mlx,
        "sprites/player/player_idle_right.xpm",
        &game->tex->width, &game->tex->height);
    player->idle_left = mlx_xpm_file_to_image(game->vars->mlx,
        "sprites/player/player_idle_left.xpm",
        &game->tex->width, &game->tex->height);
    if (!player->idle_right || !player->idle_left)
        return (0);
    return (1);
}

int load_player_sprites(t_game *game, t_player_sprites *player)
{
    char *right_paths[6];
    char *left_paths[6];

    right_paths[0] = "sprites/player/player_run_right_1.xpm";
    right_paths[1] = "sprites/player/player_run_right_2.xpm";
    right_paths[2] = "sprites/player/player_run_right_3.xpm";
    right_paths[3] = "sprites/player/player_run_right_4.xpm";
    right_paths[4] = "sprites/player/player_run_right_5.xpm";
	right_paths[5] = "sprites/player/player_run_right_6.xpm";
    left_paths[0] = "sprites/player/player_run_left_1.xpm";
    left_paths[1] = "sprites/player/player_run_left_2.xpm";
    left_paths[2] = "sprites/player/player_run_left_3.xpm";
    left_paths[3] = "sprites/player/player_run_left_4.xpm";
    left_paths[4] = "sprites/player/player_run_left_5.xpm";
	left_paths[5] = "sprites/player/player_run_left_6.xpm";
    if (!load_player_run(game, player->run_right, right_paths))
        return (0);
    if (!load_player_run(game, player->run_left, left_paths))
        return (0);
    if (!load_player_idle(game, player))
        return (0);
    player->current_frame = 0;
    player->direction = RIGHT;
    player->is_moving = 0;
    return (1);
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
