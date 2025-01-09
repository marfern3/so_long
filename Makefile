# Variables
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I include -I minilibx_opengl -I libft
LDFLAGS = -L minilibx_opengl -lmlx -framework OpenGL -framework AppKit

# Archivos fuente y objetos
SRC = srcs/so_long.c srcs/main.c srcs/map.c srcs/render.c srcs/events.c srcs/utils.c srcs/get_next_line.c srcs/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

# Regla por defecto
all: so_long

# Regla para generar el ejecutable
so_long: $(OBJ)
	$(CC) -o so_long $(OBJ) $(LDFLAGS)

# Regla para compilar los archivos .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar los archivos objeto
clean:
	rm -f $(OBJ)

# Limpiar todo (incluso el ejecutable)
fclean: clean
	rm -f so_long

# Reconstruir todo desde cero
re: fclean all
