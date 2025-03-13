#include "stdio.h"
#include "stdlib.h"
#include "utils/libft/libft.h"
#include "minilibx-linux/mlx.h"

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

// Função para desenhar um pixel
void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    char *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

// Função para desenhar um padrão de xadrez
void draw_checkerboard(t_data *img, int x_start, int y_start, int width, int height, int tile_size) {
    for (int y = y_start; y < y_start + height; y++) {
        for (int x = x_start; x < x_start + width; x++) {
            int color = ((x / tile_size + y / tile_size) % 2 == 0) ? 0xFFFFFF : 0x000000;
            my_mlx_pixel_put(img, x, y, color);
        }
    }
}

int main(void) {
    void *mlx;
    void *mlx_win;
    t_data img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    draw_checkerboard(&img, 0, 0, 1920, 1080, 50);  // Tabuleiro de xadrez de 50x50 pixels

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
