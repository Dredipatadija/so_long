#include "so_long.h"

void	ft_closemlx(char *str, t_map **map)
{
	ft_error_mlx(str, map);
	ft_free_map(*map);
}