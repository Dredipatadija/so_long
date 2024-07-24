#include "so_long.h"

t_map *ft_cpy_map(int fd, t_map *map)
{
    char    *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        map->map[map->height] = malloc(ft_strlen(line) + 1);
        if (map->map[map->height] == NULL)
        {
            close(fd);
            return NULL;
        }
        ft_memcpy(map->map[map->height], line, ft_strlen(line) + 1);
        free(line);
        map->height++;
    }
    if (map->height == 0)
    {
        ft_printf("%s\n", "Empty map");
        close(fd);
        return NULL;
    }
    map->map[map->height] = NULL;
    close(fd);
    return (map);
}