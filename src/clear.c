/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:56:11 by rdos-san          #+#    #+#             */
/*   Updated: 2025/04/01 21:35:40 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_all(t_game *game)
{
	if (game->map)
	{
		free_map(game->map, game->height);
		game->map = NULL;
	}
	if (game->mlx)
	{
		if (game->wall_img)
			mlx_destroy_image(game->mlx, game->wall_img);
		if (game->floor_img)
			mlx_destroy_image(game->mlx, game->floor_img);
		if (game->collectible_img)
			mlx_destroy_image(game->mlx, game->collectible_img);
		if (game->exit_img)
			mlx_destroy_image(game->mlx, game->exit_img);
		if (game->player_img)
			mlx_destroy_image(game->mlx, game->player_img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	exit(0);
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < height)
	{
		if (map[i])
		{
			free(map[i]);
		}
		i++;
	}
	free(map);
}

void	map_error(t_game *game, char *message)
{
	ft_printf("%s", message);
	destroy_all(game);
}
