NAME=libft.a

SRCS=ft_bzero.c \
     ft_isalpha.c \
     ft_isdigit.c \
     ft_memset.c \
     ft_isalnum.c \
     ft_isascii.c \
     ft_isprint.c \
     ft_toupper.c \
     ft_tolower.c \
     ft_strchr.c \
     ft_strrchr.c \
     ft_strncmp.c \
     ft_memchr.c \
     ft_memcmp.c \
     ft_strnstr.c \
     ft_atoi.c \
     ft_strlcat.c \
     ft_strlcpy.c \
     ft_calloc.c \
     ft_strdup.c \
     ft_strlen.c \
     ft_bzero.c \
     ft_memcpy.c \
     ft_memmove.c \
     ft_substr.c \
     ft_strjoin.c \
     ft_strtrim.c \
     ft_split.c \
     ft_strmapi.c \
     ft_striteri.c \
     ft_putchar_fd.c \
     ft_putchar.c\
     ft_putstr_fd.c \
     ft_putstr.c\
     ft_putendl_fd.c \
     ft_putnbr_fd.c \
     ft_itoa.c\
     ft_printf.c\
     ft_putpointer.c\
     ft_putnbr_base.c\
     ft_putnbr_u.c\
     ft_putnbr.c\

OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 
