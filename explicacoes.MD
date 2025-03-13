## EXPLICAÇÕES

### Código completo:
```c
dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
```

Aqui, `dst` é um ponteiro para o local de memória do pixel, e `data->addr` é o endereço base da imagem. Para entender a linha, precisamos entender como as imagens são armazenadas em memória.

#### 1. **`data->addr`**:
- `data->addr` contém o endereço base onde a imagem começa na memória. Ele é basicamente o início da memória onde os pixels da imagem estão armazenados.
- Esse endereço é retornado pela função `mlx_get_data_addr()`, que fornece o local da imagem na memória para que possamos manipulá-la diretamente.

#### 2. **`y * data->line_length`**:
- `data->line_length` representa o **número de bytes por linha da imagem**. Em outras palavras, ele indica a quantidade de memória ocupada por uma linha da imagem.
- Isso pode ser maior que a largura da imagem (em pixels) porque pode haver **padding** (espaços vazios) no final de cada linha, para garantir que cada linha da imagem comece em um endereço de memória alinhado corretamente.
- Quando multiplicamos `y` (a linha desejada) por `data->line_length`, estamos deslocando o ponteiro `data->addr` para o início da linha `y` na memória.

#### 3. **`x * (data->bits_per_pixel / 8)`**:
- `data->bits_per_pixel` diz quantos bits cada pixel ocupa na memória. Como estamos lidando com imagens em 32 bits (geralmente no formato ARGB, onde cada componente de cor (A, R, G, B) ocupa 1 byte), `data->bits_per_pixel` normalmente é 32 (8 bits para cada cor).
- Para calcular o **número de bytes por pixel**, dividimos `data->bits_per_pixel` por 8 (`data->bits_per_pixel / 8`). No caso de imagens 32 bits, isso dará 4 bytes por pixel.
- Multiplicando `x` pela quantidade de bytes por pixel, obtemos o deslocamento necessário para chegar no pixel da coluna `x` na linha desejada.

### Como funciona a expressão toda:

1. **`y * data->line_length`**: Movemos o ponteiro até o início da linha `y`.
2. **`x * (data->bits_per_pixel / 8)`**: Dentro dessa linha, movemos o ponteiro até o pixel `x` (a coluna `x`) levando em conta o tamanho de cada pixel.

### Resumo:

O cálculo `(y * data->line_length + x * (data->bits_per_pixel / 8))` nos dá o **deslocamento total** a partir do endereço base da imagem (`data->addr`) até o pixel específico que estamos buscando na posição `(x, y)`. Esse deslocamento é adicionado ao ponteiro base `data->addr`, resultando no endereço do pixel específico que queremos manipular.

### Exemplo:

Se tivermos uma imagem de 1920 pixels de largura e 1080 pixels de altura, e cada pixel ocupar 4 bytes (como no formato 32 bits), o cálculo de um pixel na posição `(x = 100, y = 50)` seria:

1. **`data->line_length`** = `1920 * 4 = 7680 bytes` (tamanho de uma linha em memória).
2. **`data->bits_per_pixel / 8`** = `4 bytes` (tamanho de cada pixel).
3. **Deslocamento para o pixel**:
   - `y * data->line_length = 50 * 7680 = 384000 bytes` (o início da linha 50).
   - `x * (data->bits_per_pixel / 8) = 100 * 4 = 400 bytes` (o deslocamento para o pixel 100 na linha 50).

Então, o endereço do pixel na posição `(100, 50)` será:

```c
dst = data->addr + (384000 + 400);  // Endereço do pixel na posição (100, 50)
```

Isso nos dá o endereço exato onde o pixel (100, 50) está armazenado na memória, e podemos modificar seu valor.
