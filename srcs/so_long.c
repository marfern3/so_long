#include "so_long.h"

void init_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        printf("Error: No se pudo inicializar minilibx.\n");
        exit(1);
    }
    game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE, game->map_height * TILE_SIZE, "so_long");
    if (!game->win)
    {
        printf("Error: No se pudo crear la ventana.\n");
        exit(1);
    }
}
void load_textures(t_game *game)
{
    int width = TILE_SIZE;
    int height = TILE_SIZE;

    game->textures.wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &width, &height);
    game->textures.floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm", &width, &height);
    game->textures.player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &width, &height);
    game->textures.collectible = mlx_xpm_file_to_image(game->mlx, "sprites/collectible.xpm", &width, &height);
    game->textures.exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &width, &height);

    if (!game->textures.wall || !game->textures.floor || !game->textures.player || !game->textures.collectible || !game->textures.exit)
    {
        printf("Error: No se pudieron cargar las texturas.\n");
        exit(1);
    }
}



void draw_map(t_game *game)
{
    int i, j;

    for (i = 0; i < game->map_height; i++)
    {
        for (j = 0; j < game->map_width; j++)
        {
            if (game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, j * TILE_SIZE, i * TILE_SIZE);
            else if (game->map[i][j] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, j * TILE_SIZE, i * TILE_SIZE);
            else if (game->map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.player, j * TILE_SIZE, i * TILE_SIZE);
            else if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.collectible, j * TILE_SIZE, i * TILE_SIZE);
            else if (game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.exit, j * TILE_SIZE, i * TILE_SIZE);
        }
    }
}
