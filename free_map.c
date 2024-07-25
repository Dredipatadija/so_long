#include "so_long.h"

void	ft_free_map(t_map *map)
{
	int	j;

	j = 0;

	while (map->map[j] != NULL)
	{
		free(map->map[j]);
		j++;
	}
	free(map->map);
	free(map);
	map = NULL;
}