/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:34:13 by rboland           #+#    #+#             */
/*   Updated: 2025/02/10 15:34:13 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_expose(t_game *game)
{
    draw_map(game, game->tex);  // You'll need to add tex to t_game structure
    return (0);
}

void draw_map(t_game *game, t_textures *tex)
{
    int x;
    int y;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == '0')
                mlx_put_image_to_window(game->vars->mlx, game->vars->win,
                    tex->floor, x * tex->width, y * tex->height);
            x++;
        }
        y++;
    }
}

int load_textures(t_game *game, t_textures *tex)
{
    char *path = "./sprites/floor/wooden.xpm";
    
    printf("Attempting to load texture from: %s\n", path);
    tex->floor = mlx_xpm_file_to_image(game->vars->mlx, 
                                      path, &tex->width, &tex->height);
    if (!tex->floor)
    {
        printf("Failed to load floor texture from: %s\n", path);
        // Try to read the file to see if it exists
        FILE *f = fopen(path, "r");
        if (!f)
            printf("File does not exist or cannot be opened\n");
        else
        {
            fclose(f);
            printf("File exists but could not be loaded as XPM\n");
        }
        return (0);
    }
    printf("Floor texture loaded successfully\n");
    return (1);
}
