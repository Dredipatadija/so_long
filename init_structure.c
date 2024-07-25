#include "so_long.h"

void	ft_init_map(t_map *map)
{
	map->nposition = 0;
	map->nexit = 0;
	map->ncollectable = 0;
	map->width = 0;
	map->height = 0;
	map->x_exit = 0;
	map->y_exit = 0;
}

void	ft_init_player(t_map *map)
{
	map->player.steps = 0;
	map->player.coin = 0;
	ft_find_position(t_map *map);
}