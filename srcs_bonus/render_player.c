/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:44:15 by rboland           #+#    #+#             */
/*   Updated: 2025/02/17 11:44:15 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void *get_direction_sprite(t_game *game, void *right_sprite, void *left_sprite)
{
    if (game->player_direction == RIGHT)
        return (right_sprite);
    return (left_sprite);
}

void *get_player_sprite(t_game *game)
{
    time_t current_time;

    if (game->duo_mode)
        return (get_direction_sprite(game, game->tex->duo_right, 
                                   game->tex->duo_left));
    if (game->flower_active)
    {
        current_time = time(NULL);
        if (current_time - game->flower_start >= 1)
        {
            game->flower_active = 0;
            return (get_direction_sprite(game, game->tex->player_right, 
                                       game->tex->player_left));
        }
        return (get_direction_sprite(game, game->tex->flower_right, 
                                   game->tex->flower_left));
    }
    return (get_direction_sprite(game, game->tex->player_right, 
                               game->tex->player_left));
}

void draw_player(t_game *game, int x, int y)
{
    void *sprite;

    sprite = get_player_sprite(game);
    mlx_put_image_to_window(game->vars->mlx, game->vars->win,
        sprite, x * TILE_SIZE, y * TILE_SIZE);
}
