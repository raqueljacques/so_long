#include "../includes/so_long.h"

static int check_valid_char(char c)
{
    return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

static void count_elements(t_game *game, char c)
{
    if (c == 'C')
        game->collectibles++;
    else if (c == 'E')
        game->exit_count++;
    else if (c == 'P')
        game->player_count++;
}

static void flood_fill(char **map, t_game *game, int x, int y, int *reachable_collectibles, int *reachable_exit) {
    // Verifica se estamos fora dos limites do mapa
    if (y < 0 || x < 0 || y >= game->height || x >= game->width)
        return;

    // Se encontramos uma parede ou já visitamos a célula, retornamos
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;

    // Se encontramos um coletável, aumentamos a contagem
    if (map[y][x] == 'C')
        (*reachable_collectibles)++;

    // Se encontramos a saída, marcamos que é acessível, mas **não sobrescrevemos**
    if (map[y][x] == 'E') {
        (*reachable_exit)++;
        return; // Não podemos marcar 'E' como visitado!
    }

    // Marca a célula como visitada
    map[y][x] = 'V';

    // Chama recursivamente para as 4 direções (cima, baixo, esquerda, direita)
    flood_fill(map, game, x + 1, y, reachable_collectibles, reachable_exit);
    flood_fill(map, game, x - 1, y, reachable_collectibles, reachable_exit);
    flood_fill(map, game, x, y + 1, reachable_collectibles, reachable_exit);
    flood_fill(map, game, x, y - 1, reachable_collectibles, reachable_exit);
}



static char **copy_map(char **map, int height) {
    char **new_map = malloc(sizeof(char *) * (height + 1));
    if (!new_map) {
        perror("Error allocating memory for map copy");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < height; i++) {
        new_map[i] = ft_strdup(map[i]);
        if (!new_map[i]) {
            perror("Error allocating memory for map row");
            // Libera as linhas já alocadas antes de retornar
            for (int j = 0; j < i; j++) {
                free(new_map[j]);
            }
            free(new_map);
            exit(EXIT_FAILURE);
        }
    }

    // Marca o fim da matriz como NULL
    new_map[height] = NULL;
    return new_map;
}


static void find_player_position(t_game *game) {
    int x;
	int y;

	x = 0;
    y = 0;
    while (y < game->height) {
        x = 0;
        while (x < game->width) {
            if (game->map[y][x] == 'P') {
                game->player_x = x; // Atualiza a posição X do jogador na struct
                game->player_y = y; // Atualiza a posição Y do jogador na struct
                return; // Sai da função assim que encontrar o jogador
            }
            x++;
        }
        y++;
    }
    printf("Erro: Posição inicial do jogador não encontrada!\n");
    exit(1); // Finaliza o programa caso o jogador não seja encontrado
}

void free_map(char **map, int height) {
    int i;

    i = 0;
    if (!map)
        return;

    while (i < height)
    {
        if (map[i]) {
            free(map[i]);
        }
        i++;
    }
    free(map);
}

static int is_map_playable(t_game *game) {
    int reachable_collectibles = 0;
    int reachable_exit = 0;

    // Localiza a posição inicial do jogador e atualiza game->player_x e game->player_y
    find_player_position(game);

    // Cria uma cópia da matriz do mapa para o Flood Fill
    char **temp_map = copy_map(game->map, game->height);

    // Começa o Flood Fill a partir da posição do jogador
     flood_fill(temp_map, game, game->player_x, game->player_y, &reachable_collectibles, &reachable_exit);


    // Libera a memória da cópia do mapa
    free_map(temp_map, game->height);

    // Verifica os critérios de jogabilidade
    if (reachable_collectibles != game->collectibles)
        return (printf("Error: Not all collectibles are accessible!\n"), 0);
    if (reachable_exit == 0)
        return (printf("Error: The exit is not accessible!\n"), 0);
    return 1;
}

static int validate_map(t_game *game)
{
    if (game->player_count != 1)
        return (printf("Error: Map must have exactly 1 player!\n"), 0);
    if (game->exit_count != 1)
        return (printf("Error: Map must have exactly 1 exit!\n"), 0);
    if (game->collectibles < 1)
        return (printf("Error: Map must have at least 1 collectible!\n"), 0);
	if (!is_map_playable(game))
		return (printf("Error: Map needs to be playable!\n"), 0);
    return (1);
}


static void	define_width(t_game *game, char *line)
{
	size_t  len;
    
    len = ft_strlen((const char *)line);
	//Se o último caractere for quebra de linha ele diminui 1 do tamanho da linha
	if (line[len - 1] == '\n')
		game->width = len - 1;
	else
		game->width = len;
	return;
}
/*
//Recebe como parâmetro o mapa e a struct que vai receber as informações
char	**load_map(char *file, t_game *game)
{
	int	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening the file"), NULL);
	
	char	*line;
	game->height = 0;
	game->width = 0;
	game->collectibles = 0;
	game->exit_count = 0;
	game->player_count = 0;

    ft_printf("chegou aqui");
	while((line = get_next_line(fd)))
	{
		int	i;
		i = 0;
	
		if (!game->width)
			define_width(game, line);

		game->map = realloc(game->map, sizeof(char *) * (game->height + 2));
		game->map[game->height] = line;
		while (i < game->width)
		{       
			if (!check_valid_char(line[i]))
				return (ft_printf("Error: Map contains invalid characters.\n"), NULL);
			count_elements(game, line[i]);
			i++;
		}
		game->height++;
	}
    ft_printf("opa");
	game->map[game->height] = NULL;
	close(fd);

	if (validate_map(game))
		return game->map;
	else
		return NULL;
}*/

char	**load_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening the file"), NULL);

	// 1. Contar a altura do mapa antes de alocar memória
	game->height = 0;
	while ((line = get_next_line(fd)))
	{
		free(line);
		game->height++;
	}
	close(fd);

	// 2. Se o mapa estiver vazio, erro
	if (game->height == 0)
		return (ft_printf("Error: Empty map.\n"), NULL);

	// 3. Alocar memória para o mapa
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (ft_printf("Error: Memory allocation failed.\n"), NULL);

	// 4. Reabrir o arquivo para carregar os dados
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror("Error reopening the file"), NULL);

	// 5. Inicializar variáveis do jogo
	game->width = 0;
	game->collectibles = 0;
	game->exit_count = 0;
	game->player_count = 0;

	// 6. Ler o mapa e armazenar as linhas
	i = 0;
	while (i < game->height && (line = get_next_line(fd)))
	{
		if (!game->width)
			define_width(game, line);

		game->map[i] = line;

		// Validar caracteres e contar elementos
		int j = 0;
		while (j < game->width)
		{
			if (!check_valid_char(line[j]))
            {
                free_map(game->map, i);
				return (ft_printf("Error: Invalid character in map.\n"), NULL);
            }
            count_elements(game, line[j]);
			j++;
		}

		i++;
	}
	game->map[game->height] = NULL; // Finalizar matriz
	close(fd);

	// 7. Validar o mapa antes de retornar
	if (validate_map(game))
		return (game->map);
	else
		return (NULL);
}
