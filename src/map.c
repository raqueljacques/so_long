/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:56:39 by rdos-san          #+#    #+#             */
/*   Updated: 2025/04/01 22:00:26 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	define_height(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening the file");
		return ;
	}
	game->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		game->height++;
		line = get_next_line(fd);
	}
	close(fd);
	if (game->height == 0)
		perror("Error: Empty map.");
}

static int	allocate_map(t_game *game)
{
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
	{
		perror("Error: Memory allocation failed.");
		return (0);
	}
	return (1);
}

static void	malloc_map(char *file, t_game *game)
{
	int	fd;

	if (!allocate_map(game))
		return ;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(game->map);
		game->map = NULL;
		perror("Error reopening the file");
		return ;
	}
	initialize_game_vars(game);
	fill_map(fd, game);
	close(fd);
}

char	**load_map(char *file, t_game *game)
{
	define_height(file, game);
	if (game->height == 0)
		return (NULL);
	game->map = NULL;
	malloc_map(file, game);
	if (!game->map)
		return (NULL);
	if (validate_map(game))
		return (game->map);
	return (NULL);
}
