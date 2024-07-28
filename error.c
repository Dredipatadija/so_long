/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmsg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:58:36 by arenilla          #+#    #+#             */
/*   Updated: 2024/07/24 11:58:37 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_msg_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	ft_err_fd(char *str, int fd, char **map)
{
	ft_printf("%s\n", str);
	close(fd);
	exit(1);
}

void	ft_err_fdfree(char *str, int fd, char **map)
{
	ft_printf("%s\n", str);
	close(fd);
	ft_free_map(map);
	exit (1);
}

	ft_err_mlxfree(char *str, void *mlx, t_map *map)
{
	ft_printf("%s\n", str);
	mlx_destroy_display(mlx);
	mlx_loop_end((*map)->mlx);
	free(mlx);
	mlx = NULL;
	ft_free_map(map);
	exit(1);
}

void	ft_msg_efree(char *str, char **map)
{
	ft_free_map(map);
	ft_printf("%s\n", str);
	exit(1);
}

void	ft_error_mlx(char *str, t_map **map)
{
	if ((*map)->images.player)
		mlx_destroy_image((*map)->mlx, (*map)->images.player);
	if ((*map)->images.wall)
		mlx_destroy_image((*map)->mlx, (*map)->images.wall);
	if ((*map)->images.floor)
		mlx_destroy_image((*map)->mlx, (*map)->images.floor);
	if ((*map)->images.exit)
		mlx_destroy_image((*map)->mlx, (*map)->images.exit);
	if ((*map)->images.coin)
		mlx_destroy_image((*map)->mlx, (*map)->images.coin);
	mlx_destroy_window((*map)->mlx, (*map)->window);
	ft_err_mlxfree(str, (*map)->mlx, *map);
}
