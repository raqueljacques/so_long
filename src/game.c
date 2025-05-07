/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:27:50 by rdos-san          #+#    #+#             */
/*   Updated: 2025/04/02 00:45:31 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	int	sprite_width;
	int	sprite_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		exit(printf("Error: Could not initialize MiniLibX!\n"));
	game->win = mlx_new_window(game->mlx, game->width * SPRITE_SIZE,
			game->height * SPRITE_SIZE, "so_long");
	if (!game->win)
		exit(printf("Error: Could not create window!\n"));
	sprite_width = SPRITE_SIZE;
	sprite_height = SPRITE_SIZE;
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&sprite_width, &sprite_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&sprite_width, &sprite_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"textures/player_right.xpm", &sprite_width, &sprite_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &sprite_width, &sprite_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&sprite_width, &sprite_height);
	if (!game->floor_img || !game->wall_img || !game->player_img
		|| !game->collectible_img || !game->exit_img)
		exit(printf("Erro: Unable to load sprites!!\n"));
}
