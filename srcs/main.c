/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:15:00 by rboland           #+#    #+#             */
/*   Updated: 2025/02/06 11:44:08 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

typedef struct s_vars {
    void    *mlx;
    void    *win;
}   t_vars;

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

int main(void)
{
    t_vars  vars;

    vars.mlx = mlx_init();
    if (!vars.mlx)
        return (1);

    vars.win = mlx_new_window(vars.mlx, 800, 600, "so_long");
    if (!vars.win)
    {
        free(vars.mlx);
        return (1);
    }

    mlx_hook(vars.win, 17, 0, handle_close, &vars);  // X button
    mlx_hook(vars.win, 2, 1L<<0, handle_keypress, &vars);  // Changed from mlx_key_hook to mlx_hook

    mlx_loop(vars.mlx);
    return (0);
}