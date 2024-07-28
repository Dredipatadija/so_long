#include "so_long.h"

char    **ft_cpy_test(t_map *map, char **test)
{
    int i;

    i = 0;
    while (map[i] != NULL)
    {
        test[i] = ft_strdup(map[i]);
        if (test[i] == NULL)
        {
            ft_free_test(test);
            ft_msg_efree("Memory failure", map->map);
        }
        i++;
    }
    test[i] = NULL;
    return (test);
}