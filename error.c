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

int	ft_msg_error(char *str, int n)
{
	ft_printf("%s\n", str);
	return (n);
}

int	ft_msg_fd(char *str, int n, int fd)
{
	ft_printf("%s\n", str);
	close(fd);
	return (n);
}

int	ft_msg_mlx(char *str, void *mlx)
{
	ft_printf("%s\n", str);
	mlx_destroy_display(mlx);
	free(mlx);
	return (1);
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
	ft_msg_mlx(str, (*map)->mlx);
	mlx_loop_end((*map)->mlx);
	free((*map)->mlx);
	(*map)->mlx = NULL;
}
