#include "../includes/so_long.h"

static void    print_moves(t_game *game)
{
    game->moves++;
    ft_putnbr(game->moves);
    ft_printf("\n");
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
    game->player_x = new_x;
    game->player_y = new_y;
    print_moves(game);
    render_map(game);
}

int handle_keypress(int keycode, t_game *game) {
    if (keycode == ESC) {
        destroy_all(game);
    } else if (keycode == KEY_W) {
        move_player(game, game->player_x, game->player_y - 1); 
    } else if (keycode == KEY_S) {
        move_player(game, game->player_x, game->player_y + 1); 
    } else if (keycode == KEY_A) {
        move_player(game, game->player_x - 1, game->player_y);
    } else if (keycode == KEY_D) {
        move_player(game, game->player_x + 1, game->player_y);
    }
    return 0;
}


int	handle_exit(t_game *game)
{
	destroy_all(game);
	return (0);
}
