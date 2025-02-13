/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:15:00 by rboland           #+#    #+#             */
/*   Updated: 2025/02/13 23:26:00 by rboland          ###   ########.fr       */
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

	printf("Starting program...\n");

    if (!check_args(argc, argv, &map, &game))
		return (1);
	
	printf("Arguments checked\n");
    vars.mlx = mlx_init();
	printf("MLX initialized\n");

	init_game(&game, &vars, &map, &tex);
	printf("Game initialized\n");

    if (!load_textures(&game, &tex))
		return (1);
	printf("Textures loaded, attempting first render...\n");
	
    render_map(&game);
	printf("First render complete\n");

    set_hooks(&vars, &game);
	printf("Hooks set\n");

    mlx_loop(vars.mlx);
    return (0);
}
