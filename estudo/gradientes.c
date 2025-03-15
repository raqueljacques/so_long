#include "stdio.h"
#include "stdlib.h"
#include "utils/libft/libft.h"
#include "minilibx-linux/mlx.h"

// Estrutura para armazenar as informações da imagem
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

// Função para desenhar um gradiente vertical
void draw_vertical_gradient(t_data *img, int x_start, int y_start, int width, int height, int color1, int color2) {
    for (int y = y_start; y < y_start + height; y++) {
        // Calcula a interpolação de cores para cada linha do gradiente
        int r1 = (color1 >> 16) & 0xFF;
        int g1 = (color1 >> 8) & 0xFF;
        int b1 = color1 & 0xFF;
        int r2 = (color2 >> 16) & 0xFF;
        int g2 = (color2 >> 8) & 0xFF;
        int b2 = color2 & 0xFF;

        // Interpola a cor de cada pixel na linha
        int r = r1 + (r2 - r1) * (y - y_start) / height;
        int g = g1 + (g2 - g1) * (y - y_start) / height;
        int b = b1 + (b2 - b1) * (y - y_start) / height;

        // Cria a cor final
        int color = (r << 16) | (g << 8) | b;

        for (int x = x_start; x < x_start + width; x++) {
            my_mlx_pixel_put(img, x, y, color);  // Desenha o pixel com a cor interpolada
        }
    }
}

int main(void) {
    void *mlx;
    void *mlx_win;
    t_data img;

    mlx = mlx_init();  // Inicializa a MiniLibX
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
    img.img = mlx_new_image(mlx, 1920, 1080);  // Cria uma nova imagem
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);  // Obtém o endereço de memória

    // Desenha um gradiente vertical de verde para vermelho
    draw_vertical_gradient(&img, 100, 100, 800, 600, 0x0000FF00, 0x00FF0000);

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);  // Coloca a imagem na janela
    mlx_loop(mlx);  // Inicia o loop da janela
}
