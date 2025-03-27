#include "../includes/so_long.h"

void find_player_position(t_game *game) {
    int x;
	int y;

	x = 0;
    y = 0;
    while (y < game->height) {
        x = 0;
        while (x < game->width) {
            if (game->map[y][x] == 'P') {
                game->player_x = x;
                game->player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
    exit(printf("Error: Player's starting position not found\n"));
}

void	initialize_game_vars(t_game *game)
{
	game->width = 0;
	game->collectibles = 0;
	game->exit_count = 0;
	game->player_count = 0;
}

char **copy_map(char **map, int height) {
    char **new_map = malloc(sizeof(char *) * (height + 1));
    if (!new_map) {
        perror("Error allocating memory for map copy");
        exit(EXIT_FAILURE);
    }
    int i;

    i = 0;
    while (i < height)
    {
        new_map[i] = ft_strdup(map[i]);
        if (!new_map[i]) {
            while (--i >= 0)
                free(new_map[i]);
            free(new_map);
            return NULL;
        }
        i++;
    }
    new_map[height] = NULL;
    return new_map;
}

int has_border_filled(t_game *game) {
    int i;

    i = 0;
    while (i < game->width)
    {
        if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
            return(0);
        i++;
    }
    i = 0;
    while (i < game->height)
    {
        if (game->map[i][0] != '1' || game->map[i][game->width -1] != '1')
            return(0);
        i++;
    }
    return(1);
}
