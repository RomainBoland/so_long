/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:15:00 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 14:23:48 by rboland          ###   ########.fr       */
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
    t_vars  vars;
    t_map   map;

    if (!check_args(argc, argv, &map))
        return (1);
    if (!init_mlx(&vars))
        return (1);
    set_hooks(&vars);
    mlx_loop(vars.mlx);
    return (0);
}