/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:18:49 by arenilla          #+#    #+#             */
/*   Updated: 2024/07/25 16:18:51 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_image(t_image *images, t_map **map)
{
	int	x;
	int	y;

	images->player = mlx_xpm_file_to_image((*map)->mlx,
			"ruta/archivo", &x, &y);
	images->wall = mlx_xpm_file_to_image((*map)->mlx,
			"ruta/archivo", &x, &y);
	images->floor = mlx_xpm_file_to_image((*map)->mlx,
			"ruta/archivo", &x, &y);
	images->exit = mlx_xpm_file_to_image((*map)->mlx,
			"ruta/archivo", &x, &y);
	images->coin = mlx_xpm_file_to_image((*map)->mlx,
			"ruta/archivo", &x, &y);
	if (images->player == NULL || images->wall == NULL || images->floor == NULL
		|| images->exit == NULL || images->coin == NULL)
	{
		ft_error_image(map);
		ft_free_map(*map);
		return (1);
	}
	return (0);
}

static int	ft_which_img(t_map **map, int x, int y)
{
	if ((*map)->map[y][x] == '1')
		return (mlx_put_image_to_window((*map)->mlx, (*map)->window,
				(*map)->images.wall, x * 64, y * 64));
	if ((*map)->map[y][x] == '0')
		return (mlx_put_image_to_window((*map)->mlx, (*map)->window,
				(*map)->images.floor, x * 64, y * 64));
	if ((*map)->map[y][x] == 'C')
		return (mlx_put_image_to_window((*map)->mlx, (*map)->window,
				(*map)->images.coin, x * 64, y * 64));
	if ((*map)->map[y][x] == 'E')
		return (mlx_put_image_to_window((*map)->mlx, (*map)->window,
				(*map)->images.exit, x * 64, y * 64));
	if ((*map)->map[y][x] == 'P')
		return (mlx_put_image_to_window((*map)->mlx, (*map)->window,
				(*map)->images.player, x * 64, y * 64));
	return (1);
}

int	ft_print_img(t_map **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while ((*map)->map[y] != NULL)
	{
		while ((*map)->map[y][x] != '\0')
		{
			if (ft_which_img(map, x, y) != 0)
			{
				ft_error_image(map);
				ft_free_map (*map);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_init_game(t_map **map)
{
	int	x;
	int	y;

	(*map)->mlx = mlx_init();
	mlx_get_screen_size((*map)->mlx, &x, &y);
	if (x < ((*map)->width * 64) || y < ((*map)->height * 64))
	{
		ft_msg_mlx("Map size too large", (*map)->mlx);
		ft_free_map(*map);
		return (1);
	}
	(*map)->window = mlx_new_window((*map)->mlx, ((*map)->width * 64),
			((*map)->height * 64), "SO_LONG");
	ft_find_exit(*map);
	if (ft_init_image(&(*map)->images, map) != 0)
		return (1);
	ft_init_player(*map);
	if (ft_print_img(map) != 0)
		return (1);
}
