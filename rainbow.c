#include "stdio.h"
#include "stdlib.h"
#include "utils/libft/libft.h"
#include "minilibx-linux/mlx.h"

// Estrutura para armazenar informações da imagem
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

// Função para desenhar o arco-íris
void draw_rainbow(t_data *img, int x_start, int y_start, int width, int height) {
    int colors[7] = {
        0xFF0000, // Vermelho
        0xFF7F00, // Laranja
        0xFFFF00, // Amarelo
        0x00FF00, // Verde
        0x0000FF, // Azul
        0x4B0082, // Anil
        0x8B00FF  // Violeta
    };

    for (int y = y_start; y < y_start + height; y++) {
        int color = colors[(y - y_start) % 7];  // Atribui a cor de acordo com a linha
        for (int x = x_start; x < x_start + width; x++) {
            my_mlx_pixel_put(img, x, y, color);  // Desenha o pixel com a cor correspondente
        }
    }
}

int main(void) {
    void *mlx;
    void *mlx_win;
    t_data img;

    mlx = mlx_init();  // Inicializa a MiniLibX
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
    img.img = mlx_new_image(mlx, 1920, 1080);  // Cria a imagem
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);  // Obtém o endereço de memória

    // Desenha o arco-íris
    draw_rainbow(&img, 100, 100, 800, 600);

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);  // Coloca a imagem na janela
    mlx_loop(mlx);  // Inicia o loop da janela
}
