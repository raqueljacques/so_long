#include "../includes/so_long.h"

void render_map(t_game *game) {
    int x, y;

    for (y = 0; y < game->height; y++) {
        for (x = 0; x < game->width; x++) {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * 32, y * 32);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x * 32, y * 32);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, x * 32, y * 32);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * 32, y * 32);
        }
    }
    
    mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->player_x * 32, game->player_y * 32);
}
