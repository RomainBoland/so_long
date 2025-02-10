/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:24:03 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 14:24:03 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_mlx(t_vars *vars)
{
    vars->mlx = mlx_init();
    if (!vars->mlx)
        return (0);
    vars->win = mlx_new_window(vars->mlx, 800, 600, "so_long");
    if (!vars->win)
    {
        free(vars->mlx);
        return (0);
    }
    return (1);
}

void set_hooks(t_vars *vars)
{
    mlx_hook(vars->win, 17, 0, handle_close, vars);
    mlx_hook(vars->win, 2, 1L<<0, handle_keypress, vars);
}
