#include "stdio.h"  // Inclui a biblioteca padrão de entrada e saída, usada para imprimir no terminal (como printf).
#include "stdlib.h" // Inclui a biblioteca padrão de utilitários (como malloc, free, exit, etc.).
#include "utils/libft/libft.h" // Inclui a biblioteca personalizada 'libft', com funções utilitárias (provavelmente criadas para o projeto, como funções para manipulação de strings, listas, etc.).
#include "minilibx-linux/mlx.h" // Inclui a biblioteca MiniLibX para criação de janelas gráficas e interação com o sistema gráfico (especificamente para o Linux).

/*int main(void)
{
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();  // Inicializa a MiniLibX e retorna um ponteiro para a instância do MLX.
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");  // Cria uma nova janela com as dimensões de 1920x1080 e o título "Hello World!".
    mlx_loop(mlx);  // Inicia o loop de renderização, fazendo com que a janela seja exibida e continue aberta até o usuário fechar.
}*/

typedef struct s_data {  // Define a estrutura 's_data' que vai armazenar informações sobre a imagem.
    void *img;            // Ponteiro para a imagem (representa a imagem na memória).
    char *addr;           // Ponteiro para o endereço de memória da imagem onde os pixels são armazenados.
    int bits_per_pixel;   // Armazena o número de bits por pixel (geralmente 32 bits para RGBA).
    int line_length;      // Armazena o comprimento de uma linha da imagem em bytes.
    int endian;           // Armazena o valor de endian (determina a ordem dos bytes em que as cores são armazenadas na memória).
} t_data;  // A estrutura 't_data' é do tipo 'struct', usada para armazenar as informações relacionadas à imagem.

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {  // Função personalizada para desenhar um pixel na imagem.
    char *dst;  // Ponteiro para o endereço de destino onde o pixel será desenhado.

    // Calcula o deslocamento da memória para acessar o pixel desejado, levando em conta a largura da linha e os bits por pixel.
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));  

    // Define a cor do pixel no endereço calculado, fazendo a conversão para um inteiro de 32 bits.
    *(unsigned int *)dst = color;
}

int main(void) {  // Função principal onde a execução do programa começa.
    void *mlx;        // Ponteiro para a instância do MLX.
    void *mlx_win;    // Ponteiro para a janela criada com o MLX.
    t_data img;       // Variável 'img' do tipo 't_data' para armazenar informações sobre a imagem.

    mlx = mlx_init();  // Inicializa a MiniLibX e retorna a instância do MLX.
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");  // Cria uma janela de 1920x1080 com o título "Hello World!".
    
    img.img = mlx_new_image(mlx, 1920, 1080);  // Cria uma nova imagem de 1920x1080 para manipular os pixels.
    
    // Obtém o endereço de memória onde a imagem é armazenada e as informações sobre os bits por pixel, a largura da linha e o endian.
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);  

    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);  // Desenha um pixel vermelho (0x00FF0000) na posição (5, 5) da imagem.

    // Coloca a imagem na janela em (0, 0) e a exibe.
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);  

    mlx_loop(mlx);  // Inicia o loop de renderização e mantém a janela aberta até o usuário fechá-la.
}
