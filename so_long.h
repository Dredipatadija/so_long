/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:58:45 by arenilla          #+#    #+#             */
/*   Updated: 2024/07/24 11:58:47 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_map
{
	int		nposition;
	int		nexit;
	int		ncollectable;
	int		width;
	int		height;
	int		x_exit;
	int		y_exit;
	char	**map;
	void	*mlx;
	void	*window;
	t_image	images;
}				t_map;

typedef struct s_image
{
	void	*player;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*coin;
}				t_image;

void	ft_init_map(t_map *map);
int		ft_parse_file(int argc, char **argmap, t_map *map);
int		ft_nlines(int fd, t_map *map);
int		ft_parse_map(int fd, t_map *map);
int		ft_parse_square(t_map *map);
int		ft_msg_error(char *str, int n);
t_map	*ft_cpy_map(int fd, t_map *map);
int		ft_parse_closed(t_map *map);
int		ft_parse_c(t_map *map);
void	ft_free_map(t_map *map);
void	ft_msg_mlx(char *str, void *mlx);

#endif
