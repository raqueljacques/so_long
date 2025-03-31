#include "../includes/so_long.h"

static void    print_moves(t_game *game)
{
    game->moves++;
    ft_putnbr(game->moves);
    ft_printf("\n");
}

static void change_image(t_game *game, int new_x, int new_y)
{
    //TODO: move to header file
    int	sprite_width;
	int	sprite_height;

    sprite_width = SPRITE_SIZE;
	sprite_height = SPRITE_SIZE;

    if (game->player_x > new_x)
        game->player_img = mlx_xpm_file_to_image(game->mlx, "assets/player_left.xpm", &sprite_width, &sprite_height);
    else if (game->player_x < new_x)
        game->player_img = mlx_xpm_file_to_image(game->mlx, "assets/player_right.xpm", &sprite_width, &sprite_height);
    else if (game->player_y > new_y)
        game->player_img = mlx_xpm_file_to_image(game->mlx, "assets/player_up.xpm", &sprite_width, &sprite_height);
    else if (game->player_y < new_y)
        game->player_img = mlx_xpm_file_to_image(game->mlx, "assets/player_down.xpm", &sprite_width, &sprite_height);
}

static void move_player(t_game *game, int new_x, int new_y) {
    if (game->map[new_y][new_x] == '1')
    {
        return;
    }
    if (game->map[new_y][new_x] == 'C') {
        game->collectibles--;
    }
    if (game->map[new_y][new_x] == 'E' && game->collectibles == 0) {
        print_moves(game);
        printf("Congratulations! You won the game!\n");
        destroy_all(game);
        return;
    } 
    else if (game->map[new_y][new_x] == 'E')
    {
        return;
    }
    game->map[game->player_y][game->player_x] = '0';
    game->map[new_y][new_x] = 'P';
    change_image(game, new_x, new_y);
    game->player_x = new_x;
    game->player_y = new_y;
    print_moves(game);
    render_map(game);
}

int handle_keypress(int keycode, t_game *game) {
    if (keycode == ESC) {
        destroy_all(game);
    } else if (keycode == KEY_W || keycode == KEY_UP) {
        move_player(game, game->player_x, game->player_y - 1); 
    } else if (keycode == KEY_S || keycode == KEY_DOWN) {
        move_player(game, game->player_x, game->player_y + 1); 
    } else if (keycode == KEY_A || keycode == KEY_LEFT) {
        move_player(game, game->player_x - 1, game->player_y);
    } else if (keycode == KEY_D || keycode == KEY_RIGHT) {
        move_player(game, game->player_x + 1, game->player_y);
    }
    return 0;
}


int	handle_exit(t_game *game)
{
	destroy_all(game);
	return (0);
}
