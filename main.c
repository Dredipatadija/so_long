#include "so_long.h"

int main(int argc, char **argv)
{
    t_map   *map;
    int     error;

    if (!argv)
    {
        ft_printf("%s\n", "Map doesn't exist");
        return (1);
    }
    map = ft_calloc(sizeof(char **), 1);
    if (!map)
        perror ("Memory failure");
    error = ft_parse_file(argc, argv, map);
}
