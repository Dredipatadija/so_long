/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:58:20 by arenilla          #+#    #+#             */
/*   Updated: 2024/07/24 11:58:22 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_parse_square(t_map *map)
{
	int	i;

	i = 0;
	while ((i < map->height) && map->map[i + 1] != NULL)
	{
		if (ft_strlen(map->map[i]) == ft_strlen(map->map[i]))
			i++;
		else
			ft_msg_efree("Map is not a square", map->map);
	}
	map->width = ft_strlen(map->map[i]);
}

static void	ft_parse_map(char *error, int fd, t_map *map)
{
	char	**test;

	map->map = (char **)malloc(sizeof(char *) * ft_nlines(fd, map) + 1);
	if (!map->map)
		ft_err_fd("Memory failure", fd, map->map);
	map = ft_cpy_map(fd, map);
	ft_parse_square(map);
	ft_parse_closed(map);
	ft_parse_c(map);
	test = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!test)
	{
		free(map->map);
		ft_msg_efree("Memory failure", test);
	}
	test = ft_cpy_test(map, test);

---------------------------------- POR AQUÍ VOY
	if (ft_okroute(test, map, map->player.x, map->player.y) != 0)
		return (ft_msg_efree(error, 1, map->map));
	return (0);
}

void	ft_parse_file(int argc, char **argmap, t_map *map)
{
	int		fd;
	int		len;
	int		lenfinal;
	char	*error;

	error = "Invalid map";
	lenfinal = ft_strlen(argmap[1]) - 4;
	len = ft_strlen(argmap[1]);
	ft_init_map(map);
	if (argc != 2)
		ft_msg_error("Invalid number of arguments");
	if (len <= 4 || ft_strncmp(&argmap[1][lenfinal], ".ber", 4) != 0)
		ft_msg_error("Invalid file");
	fd = open(argmap[1], O_RDONLY);
	if (fd < 0)
		ft_msg_error("File not found");
	ft_parse_map(error, fd, map);
}

int	ft_okroute(char **test, t_map *map, int x, int y)
{
	int	i;

	if (test[y - 1][x] != 'P' && test[y - 1][x] != '1')
		fl_okroute(test, x, y - 1);
	if (test[y + 1][x] != 'P' && test[y + 1][x] != '1')
		fl_okroute(test, x, y + 1);
	if (test[y][x - 1] != 'P' && test[y][x - 1] != '1')
		fl_okroute(test, x - 1, y);
	if (test[y][x + 1] != 'P' && test[y][x + 1] != '1')
		fl_okroute(test, x + 1, y);
	i = ft_valid(test);
	if (i == 1)
	{
		ft_free_test(test);
		return (1);
	}
	return (0);
}

int	ft_valid(char **test)
{
	int	i;
	int	j;

	i = 0;
	while (test[i])
	{
		j = 0;
		while (test[i][j])
		{
			if (test[i][j] == 'C' || test[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}