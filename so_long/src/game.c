void init_game(t_game *game) {
    game->mlx = mlx_init();
    if (!game->mlx)
        exit(printf("Error: Could not initialize MiniLibX!\n"));

    game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32, "so_long");
    if (!game->win)
        exit(printf("Error: Could not create window!\n"));

    // Carrega os sprites
    game->floor_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &sprite_width, &sprite_height);
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &sprite_width, &sprite_height);
    game->player_img = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &sprite_width, &sprite_height);
    game->collectible_img = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", &sprite_width, &sprite_height);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &sprite_width, &sprite_height);

    if (!game->grass_img || !game->tree_img || !game->player_img || !game->collectible_img || !game->exit_img)
        exit(printf("Erro: Não foi possível carregar os sprites!\n"));

    //game->moves = 0;
}
