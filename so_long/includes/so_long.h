#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/libft/libft.h"
# include "../libraries/get_next_line/get_next_line.h"

#include <fcntl.h>  // Para open()
#include <stdlib.h> // Para malloc(), free()
#include <unistd.h> // Para close(), read()
#include <stdio.h>  // Para perror()

# define ESC	65307
# define KEY_W	119
# define KEY_A	97
# define KEY_S	115
# define KEY_D	100

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

//TODO: Verificar se eu posso enfiar tudo na mesma struct
typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;
    //TODO: renomear aonde é usado para collectibles_count
    int     collectibles;
    int     exit_count;
    int     player_count;
    int     player_x;
    int     player_y;
    void    *floor_img;
    void    *wall_img;
    void    *player_img;
    void    *collectible_img;
    void    *exit_img;
} t_game;

char    **load_map(char *file, t_game *game);

#endif
