#include "so_long.h"

static void	ft_which_hook(int keycode, t_map **map)
{
	if (keycode == UP || keycode == W)
	{
		ft_move_y(map, ft_move(map), -1);
	}
	if (keycode == DOWN || keycode == S)
	{
		ft_move_y(map, ft_move(map), 1);
	}
	if (keycode == LEFT || keycode == A)
	{
		ft_move_x(map, ft_move(map), -1);
	}
	if (keycode == RIGHT || keycode == D)
	{
		ft_move_x(map, ft_move(map), 1);;
	}
}

static int	ft_move(t_map **map)
{
	char	c;

	c = (*map)->map[(*map)->player.y][(*map)->player.x - 1];
	if (c == '0')
	{
		(*map)->map[(*map)->player.y][(*map)->player.x] = '0';
		(*map)->player.steps++;
		ft_printf("Steps: %i Coins: %i\n", (*map)->player.steps,
				(*map)->player.coin);
		return (1);
	}
	if (c == 'C')
	{
		(*map)->map[(*map)->player.y][(*map)->player.x] = '0';
		(*map)->player.steps++;
		(*map)->player.coin++;
		ft_printf("Steps: %i Coins: %i\n", (*map)->player.steps,
				(*map)->player.coin);
		if ((*map)->player.coin == (*map)->ncollectable)
			(*map)->map[(*map)->y_exit][(*map)->x_exit] = 'E';
		return (1);
	}
	ft_exit(map, c);
	return (0); 
}

static void	ft_exit(t_map **map, char c)
{
	if (c == 'E')
	{
		(*map)->player.steps++;
		ft_printf("Steps: %i Coins: %i\n", (*map)->player.steps,
				(*map)->player.coin);
		ft_winner(map);
	}
}

static void ft_move_y(t_map **map, int true, int y)
{
	if (true == 1)
	{
		(*map)->player.y = (*map)->player.y + y;
		(*map)->map[(*map)->player.y][(*map)->player.x] = 'P';
	}
}

static void	ft_move_x(t_map **map, int true, int x)
{
	if (true == 1)
	{
		(*map)->player.x = (*map)->player.x + x;
		(*map)->map[(*map)->player.y][(*map)->player.x] = 'P';
	}
}

int	ft_hook(int keycode, t_map **map)
{
	if (keycode == ESC)
		ft_closemlx("Come back soon!", map);
	ft_which_hook(keycode, map);
	ft_print_img(map);
	return (0);
}
