int	load_textures2(t_game *game, t_textures *tex)
{
	tex->enemy_angry_left = mlx_xpm_file_to_image(game->vars->mlx,
		"sprites/ennemy/cali_angry_left.xpm", &tex->width, &tex->height);
	tex->enemy_angry_right = mlx_xpm_file_to_image(game->vars->mlx,
		"sprites/ennemy/cali_angry_right.xpm", &tex->width, &tex->height);
	tex->flower_left = mlx_xpm_file_to_image(game->vars->mlx,
		"sprites/player/player_flower_left.xpm", &tex->width, &tex->height);
	tex->flower_right = mlx_xpm_file_to_image(game->vars->mlx,
		"sprites/player/player_flower_right.xpm", &tex->width, &tex->height);
	tex->duo_left = mlx_xpm_file_to_image(game->vars->mlx,
		"sprites/player/duo_left.xpm", &tex->width, &tex->height);
	tex->duo_right = mlx_xpm_file_to_image(game->vars->mlx,
		"sprites/player/duo_right.xpm", &tex->width, &tex->height);
	if (!tex->enemy_angry_left || !tex->enemy_angry_right ||
		!tex->flower_left || !tex->flower_right || 
		!tex->duo_left || !tex->duo_right)
		return (0);
	return (1);
	
}

int load_textures(t_game *game, t_textures *tex)
{
    tex->floor = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/floor/wooden.xpm", &tex->width, &tex->height);
    tex->wall = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/wall/wall.xpm", &tex->width, &tex->height);
    tex->player_right = mlx_xpm_file_to_image(game->vars->mlx,
        "sprites/player/player_right.xpm", &tex->width, &tex->height);
	tex->player_left = mlx_xpm_file_to_image(game->vars->mlx,
		"sprites/player/player_left.xpm", &tex->width, &tex->height);
	tex->enemy_right = mlx_xpm_file_to_image(game->vars->mlx,
		"sprites/ennemy/cali__idle_right.xpm", &tex->width, &tex->height);
	tex->enemy_left = mlx_xpm_file_to_image(game->vars->mlx,
		"sprites/ennemy/cali_idle_left.xpm", &tex->width, &tex->height);		
    tex->collect = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/collectible/collectible.xpm", &tex->width, &tex->height);
    tex->exit = mlx_xpm_file_to_image(game->vars->mlx, 
        "sprites/exit/exit.xpm", &tex->width, &tex->height);
	tex->exit_red = mlx_xpm_file_to_image(game->vars->mlx, 
		"sprites/exit/exit_red.xpm", &tex->width, &tex->height);
    if (!tex->floor || !tex->wall || !tex->player_right || 
        !tex->collect || !tex->exit || !tex->player_left ||
		!load_textures2(game, tex))
        return (0);
    return (1);