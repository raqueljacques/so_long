NAME = solong

# Compiler flags
FLAGS = -Wall -Wextra -Werror -I./minilibx-linux -I./utils/libft -L./minilibx-linux -L./utils/libft -lmlx_Linux -lXext -lX11 -lm -lz

# Source file (only your main.c for now)
SRCS = main.c \
		teste.c

# Object files
OBJS = ${SRCS:.c=.o}

# Compiler
CC = gcc

# All target
all: ${NAME}

# Link the program and create executable
${NAME}:${OBJS}
	@$(MAKE) -C ./utils/libft  # Build the libft library
	@$(MAKE) -C ./minilibx-linux  # Build the MiniLibX library
	@${CC} ${OBJS} ${FLAGS} ./utils/libft/libft.a -o ${NAME}  # Compile and link the final binary

# Clean object files
clean:
	@${RM} ${OBJS}

# Clean everything (binary, object files, libraries)
fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C ./minilibx-linux fclean  # Clean MiniLibX
	@$(MAKE) -C ./utils/libft fclean  # Clean libft

# Rebuild everything
re: fclean all

# Run the program
run: all
	./${NAME}

# Prevent Makefile from looking for dependencies
.PHONY: clean fclean re all run
