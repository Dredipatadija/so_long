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

void	ft_parse_square(t_map **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lenmap((*map)->map[0]);
	while ((*map)->map[i])
	{
		if (len != ft_lenmap((*map)->map[i]))
			ft_msg_efree("Map is not a square", *map);
		i++;
	}
	(*map)->width = len;
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

void	ft_okroute(char **test, t_map *map, int x, int y)
{
	int	i;

	if (test[y - 1][x] != 'P' && test[y - 1][x] != '1')
		ft_okroute(test, map, x, y - 1);
	if (test[y + 1][x] != 'P' && test[y + 1][x] != '1')
		ft_okroute(test, map, x, y + 1);
	if (test[y][x - 1] != 'P' && test[y][x - 1] != '1')
		ft_okroute(test, map, x - 1, y);
	if (test[y][x + 1] != 'P' && test[y][x + 1] != '1')
		ft_okroute(test, map, x + 1, y);
	i = ft_valid(test);
	if (i == 1)
	{
		ft_free_test(test);
		ft_msg_efree("Map is not valid", map);
	}
}

void	ft_parse_map(int fd, t_map *map, char *argmap)
{
	char	**test;

	map->map = (char **)malloc(sizeof(char *) * ft_nlines(argmap, map) + 1);
	if (!map->map)
		ft_err_fd("Memory failure", fd);
	ft_cpy_map(fd, &map);
	ft_parse_square(&map);
	ft_parse_closed(&map);
	ft_printf("pare closed is ok\n");
	ft_parse_c(map);
	test = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!test)
		ft_msg_efree("Memory failure", map);
	test = ft_cpy_test(map, test);
	ft_okroute(test, map, map->player.x, map->player.y);
	ft_free_test(test);
}

void	ft_parse_file(int argc, char **argmap, t_map *map)
{
	int		fd;
	int		len;
	int		lenfinal;

	lenfinal = ft_strlen(argmap[1]) - 4;
	len = ft_strlen(argmap[1]);
	ft_init_map(map);
	if (argc != 2)
	{
		free(map);
		ft_msg_error("Invalid number of arguments");
	}
	if (len <= 4 || ft_strncmp(&argmap[1][lenfinal], ".ber", 4) != 0)
	{
		free(map);
		ft_msg_error("Invalid file");
	}
	fd = open(argmap[1], O_RDONLY);
	if (fd < 0)
	{
		free(map);
		ft_msg_error("File not found");
	}
	ft_parse_map(fd, map, argmap[1]);
}
