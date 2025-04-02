/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:56:45 by rdos-san          #+#    #+#             */
/*   Updated: 2025/04/01 21:13:06 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * SPRITE_SIZE, y
		* SPRITE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				put_image(game, game->wall_img, x, y);
			else if (game->map[y][x] == '0')
				put_image(game, game->floor_img, x, y);
			else if (game->map[y][x] == 'C')
				put_image(game, game->collectible_img, x, y);
			else if (game->map[y][x] == 'E')
				put_image(game, game->exit_img, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		game->player_x * SPRITE_SIZE, game->player_y * SPRITE_SIZE);
}
