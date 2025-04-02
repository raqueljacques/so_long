/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:56:25 by rdos-san          #+#    #+#             */
/*   Updated: 2025/04/01 21:10:29 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	define_width(t_game *game, char *line)
{
	size_t	len;

	len = ft_strlen((const char *)line);
	if (line[len - 1] == '\n')
		game->width = len - 1;
	else
		game->width = len;
	return ;
}

static void	count_elements(t_game *game, char c)
{
	if (c == 'C')
		game->collectibles++;
	else if (c == 'E')
		game->exit_count++;
	else if (c == 'P')
		game->player_count++;
}

static void	process_line(t_game *game, char *line, int row)
{
	int	j;

	if (!game->width)
		define_width(game, line);
	game->map[row] = line;
	j = 0;
	while (j < game->width)
	{
		if (!validade_char(line[j]))
		{
			free_map(game->map, row);
			exit(printf("Error: Invalid character in map.\n"));
		}
		count_elements(game, line[j]);
		j++;
	}
}

void	fill_map(int fd, t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (i < game->height && line)
	{
		process_line(game, line, i);
		i++;
		line = get_next_line(fd);
	}
	game->map[game->height] = NULL;
}
