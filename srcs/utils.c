/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:04:20 by rboland           #+#    #+#             */
/*   Updated: 2025/02/06 14:04:20 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_close(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    exit(0);
}

int handle_keypress(int keysym, t_vars *vars)
{
    printf("Key pressed: %d\n", keysym);  // Debug print
    if (keysym == 65307)    // ESC key
        handle_close(vars);
    return (0);
}
