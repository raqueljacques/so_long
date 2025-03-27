#include "../includes/so_long.h"

static void	define_width(t_game *game, char *line)
{
	size_t  len;
    
    len = ft_strlen((const char *)line);
	if (line[len - 1] == '\n')
		game->width = len - 1;
	else
		game->width = len;
	return;
}

static void count_elements(t_game *game, char c)
{
    if (c == 'C')
        game->collectibles++;
    else if (c == 'E')
        game->exit_count++;
    else if (c == 'P')
        game->player_count++;
}

void	fill_map(int fd, t_game *game)
{
	int	i;
	int	j;
	char *line;

	i = 0;
	while (i < game->height && (line = get_next_line(fd)))
	{
		if (!game->width)
			define_width(game, line);
		game->map[i] = line;
		j = 0;
		while (j < game->width)
		{
			if (!validade_char(line[j]))
            {
                free_map(game->map, i);
                exit(printf("Error: Invalid character in map.\n"));
            }
            count_elements(game, line[j]);
			j++;
		}
		i++;
	}
	game->map[game->height] = NULL;
}
