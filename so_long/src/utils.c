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

void    destroy_all(t_game *game)
{
    free_map(game->map, game->height);
    mlx_destroy_image(game->mlx, game->wall_img);
    mlx_destroy_image(game->mlx, game->floor_img);
    mlx_destroy_image(game->mlx, game->collectible_img);
    mlx_destroy_image(game->mlx, game->exit_img);
    mlx_destroy_image(game->mlx, game->player_img);
    mlx_destroy_display(game->mlx);
    mlx_destroy_window(game->mlx, game->win);
    free(game->mlx);
    exit(0);
}

void free_map(char **map, int height) {
    int i;

    i = 0;
    if (!map)
        return;

    while (i < height)
    {
        if (map[i]) {
            free(map[i]);
        }
        i++;
    }
    free(map);
}
