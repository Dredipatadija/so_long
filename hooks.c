#include "so_long.h"

void	ft_which_hook(int keycode, t_map **map)
{
	if (keycode == UP || keycode == W)
	{

	}
	if (keycode == DOWN || keycode == S)
	{

	}
	if (keycode == LEFT || keycode == A)
	{

	}
	if (keycode == RIGHT || keycode == D)
	{

	}
}


int	ft_hook(int keycode, t_map **map)
{
	if (keycode == ESC)
	{
		ft_error_mlx("Come back soon!", map);
		ft_free_map(*map);
		exit(0);
	}
	ft_which_hook(keycode, map);
	ft_print_img(map);
	return (0);
}