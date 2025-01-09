#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        printf("Uso: ./so_long <archivo_del_mapa>\n");
        return (1);
    }
    if (!read_map(argv[1], &game) || !validate_elements(&game))
        return (1);
    init_game(&game);
    load_textures(&game);
    draw_map(&game);

    mlx_loop(game.mlx); // Inicia el loop de eventos
    return (0);
}
