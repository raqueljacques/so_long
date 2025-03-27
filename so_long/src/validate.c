#include "../includes/so_long.h"

int validate_file(char *file)
{
    char *extension = ft_strrchr(file, '.');
    if (!extension || ft_strcmp(extension, ".ber") != 0)
    {
        return (0);
    }
    return (1);
}

int validade_char(char c)
{
    return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int validate_map(t_game *game)
{
    if (game->player_count != 1)
    {
        perror("Error: Map must have exactly 1 player!\n");
        destroy_all(game);
        return(0);
    }
    if (game->exit_count != 1)
    {
        perror("Error: Map must have exactly 1 exit!\n");
        destroy_all(game);
        return(0);
    }
    if (game->collectibles < 1)
    {
        perror("Error: Map must have at least 1 collectible!\n");
        destroy_all(game);
        return(0);
    }
	if (!is_map_playable(game) || !has_border_filled(game))
    {
        perror("Error: Map needs to be playable!\n");
        destroy_all(game);
		return(0);
    }
    return (1);
}

static void flood_fill(char **map, t_game *game, int x, int y, int *reachable_collectibles, int *reachable_exit) {
    if (y < 0 || x < 0 || y >= game->height || x >= game->width)
        return;
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;
    if (map[y][x] == 'C')
        (*reachable_collectibles)++;
    if (map[y][x] == 'E') {
        (*reachable_exit)++;
        return;
    }
    map[y][x] = 'V';
    flood_fill(map, game, x + 1, y, reachable_collectibles, reachable_exit);
    flood_fill(map, game, x - 1, y, reachable_collectibles, reachable_exit);
    flood_fill(map, game, x, y + 1, reachable_collectibles, reachable_exit);
    flood_fill(map, game, x, y - 1, reachable_collectibles, reachable_exit);
}

int is_map_playable(t_game *game) {
    int reachable_collectibles = 0;
    int reachable_exit = 0;

    find_player_position(game);
    char **temp_map = copy_map(game->map, game->height);
    flood_fill(temp_map, game, game->player_x, game->player_y, &reachable_collectibles, &reachable_exit);
    free_map(temp_map, game->height);
   
    if (reachable_collectibles != game->collectibles)
        return (printf("Error: Not all collectibles are accessible!\n"), 0);
    if (reachable_exit == 0)
        return (printf("Error: The exit is not accessible!\n"), 0);
    return 1;
}
