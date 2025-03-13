#include "stdio.h"
#include "stdlib.h"
#include "utils/libft/libft.h"
#include "minilibx-linux/mlx.h"

// Estrutura que contém informações sobre a imagem
typedef struct s_data {
    void *img;            // Ponteiro para a imagem
    char *addr;           // Endereço de memória da imagem
    int bits_per_pixel;   // Bits por pixel (geralmente 32)
    int line_length;      // Tamanho da linha da imagem
    int endian;           // Ordem de bytes na memória
} t_data;

// Função para desenhar um pixel em uma posição específica da imagem
void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    char *dst;
    // Calcula o deslocamento de memória para o pixel (x, y)
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    // Atribui a cor ao pixel
    *(unsigned int *)dst = color;
}

// Função para desenhar um quadrado
void draw_square(t_data *img, int x_start, int y_start, int size, int color) {
    for (int y = y_start; y < y_start + size; y++) {
        for (int x = x_start; x < x_start + size; x++) {
            my_mlx_pixel_put(img, x, y, color);  // Chama a função para cada pixel do quadrado
        }
    }
}

// Função para desenhar um círculo
void draw_circle(t_data *img, int x_center, int y_center, int radius, int color) {
    for (int y = y_center - radius; y <= y_center + radius; y++) {
        for (int x = x_center - radius; x <= x_center + radius; x++) {
            // Verifica se o ponto está dentro do círculo
            int dx = x - x_center;
            int dy = y - y_center;
            if (dx * dx + dy * dy <= radius * radius) {
                my_mlx_pixel_put(img, x, y, color);  // Desenha o pixel dentro do círculo
            }
        }
    }
}

int main(void) {
    void *mlx;
    void *mlx_win;
    t_data img;

    mlx = mlx_init();  // Inicializa a MiniLibX
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");  // Cria uma nova janela com 1920x1080 de tamanho
    img.img = mlx_new_image(mlx, 1920, 1080);  // Cria uma nova imagem
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);  // Obtém o endereço da imagem

    // Desenha um quadrado vermelho e um círculo verde
    draw_square(&img, 100, 100, 200, 0x00FF0000);  // Quadrado vermelho
    draw_circle(&img, 500, 500, 100, 0x0000FF00);  // Círculo verde

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);  // Coloca a imagem na janela
    mlx_loop(mlx);  // Inicia o loop da janela, mantendo-a aberta
}
