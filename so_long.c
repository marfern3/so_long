#include "so_long.h"

int main(int argc, char **argv)
{
    void *mlx;
    void *win;

    (void)argc;
    (void)argv;
    (void)win;
    
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "so_long");
    mlx_loop(mlx);
    return (0);
}