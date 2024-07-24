#include "so_long.h"

int ft_parse_file(int argc, char *argmap, t_map *map)
{
    int fd;

    if (argc != 2)
        return (ft_print_e("Invalid number of arguments", 1));
    if (ft_strlen(argmap) <= 4 || ft_strncmp(&argmap[ft_strlen(argmap) - 4], ".ber", 4) != 0)
        return (ft_print_e("Invalid file", 1));
    fd = open(argmap, O_RDONLY);
    if (fd < 0)
        return (ft_print_e("File not found", 1));
    return (ft_parse_map(fd, map));
}

int ft_parse_map(int fd, t_map *map) 
{
    char    *error;

    error = "Invalid map";
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