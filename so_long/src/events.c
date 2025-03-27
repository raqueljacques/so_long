#include "../includes/so_long.h"


static void move_player(t_game *game, int new_x, int new_y) {
    // Verificar se o movimento é para fora do mapa não faz sentido pq a borda estará preenchida

    // Verifica se o jogador está tentando atravessar uma parede
    if (game->map[new_y][new_x] == '1')
    {
        return;
    }
    // Se pisar em um coletável, decrementa o contador
    if (game->map[new_y][new_x] == 'C') {
        game->collectibles--;
    }

    // Se pisar na saída e todos os coletáveis foram pegos, fecha o jogo
    if (game->map[new_y][new_x] == 'E' && game->collectibles == 0) {
        printf("Congratulations! You won the game!\n");
		// TODO: Dar free na matriz inteira
		free_map(game->map, game->height);
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    } else if (game->map[new_y][new_x] == 'E')
    {
        return;
    }
    // Atualiza a posição do jogador no mapa
    game->map[game->player_y][game->player_x] = '0'; //Coloca o chão na posição antiga
    game->map[new_y][new_x] = 'P'; // Atualiza a posição do jogador
    game->player_x = new_x;
    game->player_y = new_y;

    // Renderiza o mapa após o movimento
    render_map(game);
}

int handle_keypress(int keycode, t_game *game) {
    if (keycode == ESC) {
        mlx_destroy_window(game->mlx, game->win);
        exit(0); // Fecha o jogo
    } else if (keycode == KEY_W) {
        move_player(game, game->player_x, game->player_y - 1); 
    } else if (keycode == KEY_S) {
        move_player(game, game->player_x, game->player_y + 1); 
    } else if (keycode == KEY_A) {
        move_player(game, game->player_x - 1, game->player_y);
    } else if (keycode == KEY_D) {
        move_player(game, game->player_x + 1, game->player_y);
    }
    return 0; // Retorna 0 para indicar que o evento foi tratado
}

int	handle_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
