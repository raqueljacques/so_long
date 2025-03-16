#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
    t_game game;
    //TODO: verificar se o arquivo enviado é um ".ber"?
    if (argc != 2)
    {
        ft_printf("Error: invalid number of arguments\n");
        return (1);
    }
    if (!load_map(argv[1], &game))
    {
        ft_printf("Error: invalid map\n");
        return (1);
    }
    // Inicializa o jogo (carrega mapa, inicializa MiniLibX, etc.)
    init_game(&game);

    // Renderiza o mapa na tela pela primeira vez
    render_map(&game);

    //Registrar eventos
    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_loop(game.mlx);
    return (0);
}
