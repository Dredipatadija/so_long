#include "so_long.h"

t_map *ft_cpy_map(int fd, t_map *map)
{
    char    *line;
    int     round;
    int     i;

    i = 0;
    round = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
        {
            if (round == 0)
            {
                ft_printf("%s\n", "Empty map");
                close(fd);
                return ((void *)0);
            }
            else
            {
                free(line);
                break;
            }
        }
        map->map[i][0] = ft_memcpy(map->map[i][0], line, ft_strlen(line));
        i++;
        round++;
        free(line);      
    }
    map->map[i][0] = (void *)0;
    return (map);
}