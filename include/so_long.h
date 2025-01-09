#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 
#include "libft.h"
#include "mlx.h"

#define TILE_SIZE 32  // Asegúrate de definir TILE_SIZE si aún no lo has hecho

typedef struct s_textures
{
    void *wall;
    void *floor;
    void *player;
    void *collectible;
    void *exit;
} t_textures;

typedef struct s_game
{
    void *mlx;
    void *win;
    char **map;
    int map_width;
    int map_height;
    int tile_size;  // Asegúrate de tener el campo tile_size aquí
    t_textures textures;
} t_game;

char    **read_map(const char *file_path, t_game *game);
void    init_game(t_game *game);
void    load_textures(t_game *game);
void    draw_map(t_game *game);
int     validate_elements(t_game *game);

#endif
