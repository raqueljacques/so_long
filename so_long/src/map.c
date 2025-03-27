#include "../includes/so_long.h"

static void define_height(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening the file");
		return;
	}
	game->height = 0;
	while ((line = get_next_line(fd)))
	{
		free(line);
		game->height++;
	}
	close(fd);
	if (game->height == 0)
	{
		perror("Error: Empty map.");
		return;
	}
}


static void malloc_map(char *file, t_game *game)
{
	int		fd;

	game->map = NULL;
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
	{
		perror("Error: Memory allocation failed.");
		return;
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(game->map);
		perror("Error reopening the file");
		return;
	}
	initialize_game_vars(game);
	fill_map(fd, game);
	close(fd);
}
char **load_map(char *file, t_game *game)
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
