#include "so_long.h"

void    ft_init_map(t_map *map)
{
    map->nposition = 0;
    map->nexit = 0;
    map->ncollectable = 0;
    map->nwall = 0;
    map->nspace = 0;
    map->width = 0;
    map->height = 0;
    map->x_exit = 0;
    map->y_exit = 0;
}

int ft_parse_file(int argc, char *argmap, t_map *map)
{
    int fd;

    ft_init_map(map);
    if (argc != 2)
        return (ft_print_e("Invalid number of arguments", 1));
    if (ft_strlen(argmap) <= 4 || ft_strncmp(&argmap[ft_strlen(argmap) - 4], ".ber", 4) != 0)
        return (ft_print_e("Invalid file", 1));
    fd = open(argmap, O_RDONLY);
    if (fd < 0)
        return (ft_print_e("File not found", 1));
    return (ft_parse_map(fd, map));
}

int ft_nlines(fd)
{
    int     i;
    char    *line;

    i = 0;
    while (((line = get_next_line(fd)) != NULL))
    {
        i++;
    }
    free (line);
    if (i == 0)
    {
        ft_printf("%s\n", "Empty map");
        close(fd);
        return NULL;
    }
    return (i);
}

int ft_parse_map(int fd, t_map *map) 
{
    char    *error;

    error = "Invalid map";
    map->map = (char **)malloc(sizeof(char *) * ft_nlines(fd));
    if (!map->map)
        return (1);
    map = ft_cpy_map(fd, map);
    if (!map)
        return (ft_print_e("Memory error", 1));
    if (ft_parse_square(map) != 0)
        return (ft_print_e(error, 1));
    if (ft_parse_closed(map) != 0)
        return (ft_print_e(error, 1));
    if (ft_parse_exit(map) != 0)
        return (ft_print_e(error, 1));
    if (ft_parse_initpos(map) != 0)
        return (ft_print_e(error, 1));
    if (ft_parse_collec(map) != 0)
        return (ft_print_e(error, 1));
    return (0);
}

int ft_parse_square(t_map *map)
{

}