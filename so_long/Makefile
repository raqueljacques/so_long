NAME = so_long

FLAGS = -Wall -Wextra -Werror -I./includes -I./libraries/minilibx-linux -I./libraries/libft -L./libraries/minilibx-linux -L./libraries/libft -lmlx_Linux -lXext -lX11 -lm -lz

SRC_DIR = ./src/

SRCS = $(addprefix $(SRC_DIR), \
	clear.c \
	events.c \
	fill_map_utils.c \
    game.c \
    map.c \
	render.c \
    so_long.c \
	utils.c \
	validate.c)

OBJS = $(SRCS:.c=.o)

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libraries/libft
	@$(MAKE) -C ./libraries/minilibx-linux
	@$(CC) $(OBJS) $(FLAGS) ./libraries/libft/libft.a -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C ./libraries/libft fclean
	@$(MAKE) -C ./libraries/minilibx-linux clean

re: fclean all

run: all
	./$(NAME)

.PHONY: clean fclean re all run
