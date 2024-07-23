int ft_parse_file(int argc, char *argmap, char **map)
{
    int fd;

    if (argc != 2)
    {
        ft_printf("%s\n", "Invalid number of arguments");
        return (1);
    }
    if (ft_strlen(argmap) <= 4 || ft_strncmp(&argmap[ft_strlen(argmap) - 4], ".ber", 4) != 0)
    {
        ft_printf("%s\n", "Invalid file");
        return (1);
    }
    fd = open(argmap, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("%s\n", "File not found");
        return (1);
    }
    return (ft_parse_map(fd, map));
}

int ft_parse_map(int fd, char **map)
{
    char    *error;

    error = "Invalid map";
    map = ft_cpy_map(fd, map);
    if (!map)
        return (1);
    if (ft_parse_square(map) != 0)
    {
        ft_printf("%s\n", error);
        return (1);
    }
    if (ft_parse_closed(map) != 0)
    {
        ft_printf("%s\n", error);
        return (1);
    }
    if (ft_parse_exit(map) != 0)
    {
        ft_printf("%s\n", error);
        return (1);
    }
    if (ft_parse_initpos(map) != 0)
    {
        ft_printf("%s\n", error);
        return (1);
    }
    if (ft_parse_collec(map) != 0)
    {
        ft_printf("%s\n", error);
        return (1);
    }
    return (0);
}