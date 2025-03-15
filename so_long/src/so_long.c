#include "so_long.h"

int	main(int argc, char **argv)
{
    t_game game;
    //TODO: verificar se o arquivo enviado é um ".ber"?
    if (argc != 2)
    {
        ft_printf("Error: invalid number of arguments\n");
        return (1);
    }
    if (!load_map(&game, argv[1]))
    {
        ft_printf("Error: invalid map\n");
        return (1);
    }
    init_game(&game);
    render_map(&game);

    //Registrar eventos
    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_loop(game.mlx);
    return (0);
}
