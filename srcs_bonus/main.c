/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:15:00 by rboland           #+#    #+#             */
/*   Updated: 2025/02/14 11:30:22 by rboland          ###   ########.fr       */
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
	t_enemy		enemy;

	(void)enemy;
	
	// printf("About to check for args...\n");
    if (!check_args(argc, argv, &map, &game))
		return (1);
	// printf("Args checked successfuly!\n");
	
	// printf("About to niti mlx...\n");
    vars.mlx = mlx_init();
	// printf("Mlx initialized successfuly !\n");
	
	// printf("About the try to init game...\n");
	init_game(&game, &vars, &map, &tex);
	// printf("Init game successfuly!\n");
	
	// printf("About to load texture...\n");
    if (!load_textures(&game, &tex))
		return (1);
	// printf("Textures loaded successfuly !\n");
	
	// printf("Trying first render...\n");
    render_map(&game);
	// printf("First render successful !\n");
	
	// printf("About to set hook\n");
    set_hooks(&vars, &game);
	// printf("Hooked set up!\n");

	// printf("About to enter the loop\n");
    mlx_loop(vars.mlx);
    return (0);
}
