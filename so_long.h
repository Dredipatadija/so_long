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
# include "./mlx_linux/mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef hooks
#  define ESC	65307
#  define DOWN	65364
#  define UP	65362
#  define LEFT	65361
#  define RIGHT	65363
#  define W		119
#  define A		97
#  define S		115
#  define D		100
# endif

typedef struct s_image
{
	void	*player;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*coin;
}				t_image;

typedef struct s_player
{
	int	steps;
	int	coin;
	int	x;
	int	y;
}			t_player;

typedef struct s_map
{
	int			nposition;
	int			nexit;
	int			ncollectable;
	int			width;
	int			height;
	int			x_exit;
	int			y_exit;
	char		**map;
	void		*mlx;
	void		*window;
	t_image		images;
	t_player	player;
}				t_map;

int	ft_msg_error(char *str, int n);
int	ft_msg_fd(char *str, int n, int fd, char **map);
int	ft_msg_mlx(char *str, void *mlx);
int	ft_msg_efree(char *str, int n, char **map);
void	ft_error_mlx(char *str, t_map **map);
void	ft_free_map(t_map *map);
void	ft_free_test(char **test);
int	ft_hook(int keycode, t_map **map);
void	ft_which_hook(int keycode, t_map **map);
int	ft_move(t_map **map);
void	ft_exit(t_map **map, char c);
void ft_move_y(t_map **map, int true, int y);
void	ft_move_x(t_map **map, int true, int x);
void	ft_init_image(t_image *images, t_map **map);
void	ft_print_img(t_map **map);
int	ft_init_game(t_map **map);
void	ft_init_map(t_map *map);
void	ft_init_player(t_map *map);
int	ft_parse_closed(t_map *map);
int	ft_parse_c(t_map *map);
int	ft_parse_file(int argc, char **argmap, t_map *map);
int	ft_parse_map(char *error, int fd, t_map *map);
int	ft_okroute(char **test, t_map *map, int x, int y);
int	ft_valid(char **test);
t_map	*ft_cpy_map(int fd, t_map *map);
int	ft_nlines(int fd, t_map *map);
void	ft_find_exit(t_map *map);
void	ft_find_position(t_map *map);
char	**ft_cpy_test(t_map *map, char **test);
int	ft_closemlx(char *str, t_map **map);
int	main(int argc, char **argv);

#endif
