/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:24:00 by rdos-san          #+#    #+#             */
/*   Updated: 2025/04/01 21:24:01 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define CLOSE_WINDOW 17
# define ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define SPRITE_SIZE 64

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		collectibles;
	int		reachable_collectibles;
	int		reachable_exit;
	int		exit_count;
	int		player_count;
	int		player_x;
	int		player_y;
	int		moves;
	void	*floor_img;
	void	*wall_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
}			t_game;

int			validate_file(char *file);

void		destroy_all(t_game *game);
void		free_map(char **map, int height);

int			handle_keypress(int keycode, t_game *game);
int			handle_exit(t_game *game);

void		fill_map(int fd, t_game *game);

void		init_game(t_game *game);

char		**load_map(char *file, t_game *game);

void		render_map(t_game *game);

char		**copy_map(char **map, int height);

void		initialize_game_vars(t_game *game);
void		find_player_position(t_game *game);

int			validate_map(t_game *game);
int			validade_char(char c);
int			validate_file(char *file);
int			has_border_filled(t_game *game);
#endif
