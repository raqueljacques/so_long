/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:20:35 by rdos-san          #+#    #+#             */
/*   Updated: 2025/03/26 23:22:18 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit(printf("Error: invalid number of arguments\n"));
	if (!validate_file(argv[1]) || !load_map(argv[1], &game))
		exit(printf("Error: invalid type of file or map\n"));
	init_game(&game);
	render_map(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, CLOSE_WINDOW, 0, handle_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
