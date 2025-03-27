/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:27:50 by rdos-san          #+#    #+#             */
/*   Updated: 2025/03/27 03:10:39 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game) {
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(printf("Error: Could not initialize MiniLibX!\n"));
	game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32, "so_long");
	if (!game->win)
		exit(printf("Error: Could not create window!\n"));
	int	sprite_width;
	int	sprite_height;

	sprite_width = 32;
	sprite_height = 32;
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &sprite_width, &sprite_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &sprite_width, &sprite_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &sprite_width, &sprite_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", &sprite_width, &sprite_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &sprite_width, &sprite_height);
	if (!game->floor_img || !game->wall_img || !game->player_img || !game->collectible_img || !game->exit_img)
		exit(printf("Erro: Unable to load sprites!!\n"));
    //TODO: Contabilizar os movimentos
    //game->moves = 0;
}
