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

void	ft_init_image(t_image *images, t_map **map)
{
	int	x;
	int	y;

	images->player = mlx_xpm_file_to_image((*map)->mlx,
			"files_mlx/player.mlx", &x, &y);
	images->wall = mlx_xpm_file_to_image((*map)->mlx,
			"files_mlx/wall.mlx", &x, &y);
	images->floor = mlx_xpm_file_to_image((*map)->mlx,
			"files_mlx/floor.mlx", &x, &y);
	images->exit = mlx_xpm_file_to_image((*map)->mlx,
			"files_mlx/exit.mlx", &x, &y);
	images->coin = mlx_xpm_file_to_image((*map)->mlx,
			"files_mlx/coi.mlx", &x, &y);
	if (images->player == NULL || images->wall == NULL || images->floor == NULL
		|| images->exit == NULL || images->coin == NULL)
	{
		ft_error_mlx("Error loading image", map);
		ft_free_map(*map);
		exit(1);
	}
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

void	ft_print_img(t_map **map)
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
				ft_error_mlx("Error showing image", map);
				ft_free_map (*map);
				exit(1);
			}
			x++;
		}
		y++;
	}
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
	ft_init_image(&(*map)->images, map);
	ft_init_player(*map);
	ft_print_img(map);
	ft_printf("Steps: %i Coins: %i\n", (*map)->player.steps,
			(*map)->player.coin);
	mlx_hook((*map)->window, 17, 0, ft_closemlx("Come back soon", map), map);
	mlx_hook((*map)->window, 2, 1L<<0, ft_hook, map);
	mlx_loop((*map)->mlx);
}