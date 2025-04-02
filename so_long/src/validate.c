/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:57:00 by rdos-san          #+#    #+#             */
/*   Updated: 2025/04/01 22:12:32 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (y < 0 || x < 0 || y >= game->height || x >= game->width)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		game->reachable_collectibles++;
	if (map[y][x] == 'E')
	{
		game->reachable_exit = 1;
		return ;
	}
	map[y][x] = 'V';
	flood_fill(map, game, x + 1, y);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x, y - 1);
}

int	validate_file(char *file)
{
	char	*extension;

	extension = ft_strrchr(file, '.');
	return (extension && ft_strcmp(extension, ".ber") == 0);
}

int	validade_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

static int	is_map_playable(t_game *game)
{
	char	**temp_map;

	game->reachable_collectibles = 0;
	game->reachable_exit = 0;
	find_player_position(game);
	temp_map = copy_map(game->map, game->height);
	flood_fill(temp_map, game, game->player_x, game->player_y);
	free_map(temp_map, game->height);
	if (game->reachable_collectibles != game->collectibles)
	{
		printf("Error: Not all collectibles are accessible!\n");
		return (0);
	}
	if (!game->reachable_exit)
	{
		printf("Error: The exit is not accessible!\n");
		return (0);
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (game->player_count != 1)
	{
		map_error(game, "Error: Map must have exactly 1 player!\n");
		return (0);
	}
	if (game->exit_count != 1)
	{
		map_error(game, "Error: Map must have exactly 1 exit!\n");
		return (0);
	}
	if (game->collectibles < 1)
	{
		map_error(game, "Error: Map must have at least 1 collectible!\n");
		return (0);
	}
	if (!is_map_playable(game) || !has_border_filled(game))
	{
		map_error(game, "Error: Map needs to be playable!\n");
		return (0);
	}
	return (1);
}
