/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:15:00 by rboland           #+#    #+#             */
/*   Updated: 2025/02/12 16:00:07 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_args(int argc, char **argv, t_map *map)
{
    if (argc != 2)
        error_map(NULL, "Usage: ./so_long [map.ber]");
    if (!get_map_error(argv[1], map))
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    t_vars      vars;
    t_map       map;
    t_game      game;
    t_textures  tex;

    if (!check_args(argc, argv, &map))
        return (1);
    vars.mlx = mlx_init();
    if (!vars.mlx)
        return (1);
    if (!init_game(&game, &vars, &map))
        return (1);
    game.tex = &tex;
    if (!load_textures(&game, &tex))
    {
        free_map(&map);
        return (1);
    }
    render_map(&game);
    set_hooks(&vars, &game);
    mlx_loop(vars.mlx);
    return (0);
}
