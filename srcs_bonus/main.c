/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:15:00 by rboland           #+#    #+#             */
/*   Updated: 2025/02/13 23:47:10 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int check_args(int argc, char **argv, t_map *map, t_game *game)
{
    if (argc != 2)
        error_map(NULL, "Usage: ./so_long [map.ber]");
    if (!get_map_error(argv[1], map, game))
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    t_vars      vars;
    t_map       map;
    t_game      game;
    t_textures  tex;


    if (!check_args(argc, argv, &map, &game))
		return (1);
    vars.mlx = mlx_init();
	init_game(&game, &vars, &map, &tex);
    if (!load_textures(&game, &tex))
		return (1);
    render_map(&game);
    set_hooks(&vars, &game);
    mlx_loop(vars.mlx);
    return (0);
}
