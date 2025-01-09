#include "so_long.h"
#include "get_next_line.h"
#include <stdio.h> // Para perror y printf
#include <string.h> // Para strlen


char **read_map(const char *file_path, t_game *game)
{
    int fd = open(file_path, O_RDONLY);
    char *line;
    char **map = malloc(sizeof(char *) * 100);
    int i = 0;

    if (fd < 0 || !map)
        return (perror("Error al abrir el archivo o asignar memoria"), NULL);
    while ((line = get_next_line(fd)))
    {
        if (i >= 100)
            map = realloc(map, sizeof(char *) * (i + 1));
        map[i++] = line;
        if (!line) break;
    }
    close(fd);
    game->map_width = strlen(map[0]);
    game->map_height = i;
    return (map);
}



int validate_map(t_game *game)
{
    int i, j;

    if (!game->map || game->map_height < 3 || game->map_width < 3)
    {
        printf("Error: El mapa es demasiado pequeño o es nulo.\n");
        return (0);
    }
    for (i = 0; i < game->map_height; i++)
    {
        if ((int)strlen(game->map[i]) != game->map_width)
        {
            printf("Error: El mapa no es rectangular. Fila %d tiene longitud %ld (esperada: %d).\n", i, strlen(game->map[i]), game->map_width);
            return (0);
        }
        for (j = 0; j < game->map_width; j++)
        {
            if ((i == 0 || i == game->map_height - 1 || j == 0 || j == game->map_width - 1) &&
                game->map[i][j] != '1')
            {
                printf("Error: El mapa no está rodeado de muros en fila %d, columna %d.\n", i, j);
                return (0);
            }
        }
    }
    return (validate_elements(game)); // Validar elementos adicionales (jugador, salida, coleccionables)
}
void count_elements(t_game *game, int *player, int *exit, int *collectible)
{
    int i, j;

    for (i = 0; i < game->map_height; i++)
        for (j = 0; j < game->map_width; j++)
        {
            if (game->map[i][j] == 'P')
                (*player)++;
            else if (game->map[i][j] == 'E')
                (*exit)++;
            else if (game->map[i][j] == 'C')
                (*collectible)++;
        }
}

int validate_elements(t_game *game)
{
    int player = 0, exit = 0, collectible = 0;

    count_elements(game, &player, &exit, &collectible);
    if (player != 1)
    {
        printf("Error: El mapa debe tener exactamente 1 jugador ('P').\n");
        return 0;
    }
    if (exit < 1)
    {
        printf("Error: El mapa debe tener al menos 1 salida ('E').\n");
        return 0;
    }
    if (collectible < 1)
    {
        printf("Error: El mapa debe tener al menos 1 coleccionable ('C').\n");
        return 0;
    }
    return 1;
}


void free_map(char **map)
{
    int i;

    if (!map)
        return;
    for (i = 0; map[i]; i++)
        free(map[i]);
    free(map);
}
