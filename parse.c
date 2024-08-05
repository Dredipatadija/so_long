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

	i = 0;
	while ((*map)->map[i + 1])
	{
		if (ft_lenmap((*map)->map[i]) != ft_lenmap((*map)->map[i]))
			ft_msg_efree("Map is not a square", *map);
		i++;
	}
	(*map)->width = ft_lenmap((*map)->map[0]);
}

void	ft_valid(char **test, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (test[j])
	{
		i = 0;
		while (test[j][i])
		{
			if (test[j][i] == 'C' || test[j][i] == 'E')
			{
				ft_free_test(test);
				ft_msg_efree("Map is not valid", map);
			}
			i++;
		}
		j++;
	}
}

void	ft_okroute(char **test, int x, int y)
{
	test[y][x] = 'P';
	if (test[y - 1][x] != 'P' && test[y - 1][x] != '1')
		ft_okroute(test, x, y - 1);
	if (test[y + 1][x] != 'P' && test[y + 1][x] != '1')
		ft_okroute(test, x, y + 1);
	if (test[y][x - 1] != 'P' && test[y][x - 1] != '1')
		ft_okroute(test, x - 1, y);
	if (test[y][x + 1] != 'P' && test[y][x + 1] != '1')
		ft_okroute(test, x + 1, y);
}

void	ft_parse_map(int fd, t_map *map, char *argmap)
{
	char	**test;

	map->map = (char **)malloc(sizeof(char *) * ft_nlines(argmap, map) + 1);
	if (!map->map)
		ft_err_fd("Memory allocation failed for map", fd);
	ft_cpy_map(fd, &map);
	if (map->map[0] == NULL)
		ft_msg_efree("Error while copying map", map);
	ft_parse_square(&map);
	if (map->width > 164 && map->height > 64)
		ft_msg_efree("Map is too big", map);
	ft_parse_closed(&map);
	ft_parse_c(&map);
	test = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!test)
		ft_msg_efree("Memory failure", map);
	test = ft_cpy_test(map, test);
	ft_okroute(test, map->player.x, map->player.y);
	ft_valid(test, map);
	ft_free_test(test);
}

void	ft_parse_file(char **argmap, t_map *map)
{
	int		fd;
	int		len;
	int		lenfinal;

	lenfinal = ft_strlen(argmap[1]) - 4;
	len = ft_strlen(argmap[1]);
	ft_init_map(map);
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
