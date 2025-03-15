NAME = solong

#TODO: O que significa -I e -L?
FLAGS = -Wall -Wextra -Werror -I./libraries/minilibx-linux -I./libraries/libft -L./libraries/minilibx-linux -L./libraries/libft -lmlx_Linux -lXext -lX11 -lm -lz

SRC_DIR = ./src/

SRCS = $(addprefix $(SRC_DIR),\
							so_long.c \
							map.c \
							game.c \
							events)

OBJS = ${SRCS:.c=.o}

CC = cc

all: ${NAME}

${NAME}:${OBJS}
	@$(MAKE) -C ./libraries/libft  # Build the libft library
	@$(MAKE) -C ./libraries/get_next_line  # Build the get next line library
	@$(MAKE) -C ./libraries/minilibx-linux  # Build the MiniLibX library
	@${CC} ${OBJS} ${FLAGS} ./libraries/libft/libft.a -o ${NAME}  # Compile and link the final binary

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C ./libraries/minilibx-linux fclean  # Clean MiniLibX
	@$(MAKE) -C ./libraries/get_next_line fclean # Clean get next line
	@$(MAKE) -C ./libraries/libft fclean  # Clean libft

re: fclean all

run: all
	./${NAME}

.PHONY: clean fclean re all run
