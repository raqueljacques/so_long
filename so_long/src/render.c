#include "../includes/so_long.h"

void render_map(t_game *game) {
    int x;
    int y;

    y = 0;
    while(y < game->height)
    {
        x = 0;
        while(x < game->width)
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
            x++;
        }
        y++;
    }
    display_collectibles(game);
    mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->player_x * SPRITE_SIZE, game->player_y * SPRITE_SIZE);
}

void display_collectibles(t_game *game)
{
    char *count;
    char *text;

    count = ft_itoa(game->collectibles);
    text = ft_strjoin("Collectibles left: ", count);
    mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, text);
    free(count);
    free(text);
}