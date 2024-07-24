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

void	ft_init_map(t_map *map)
{
	map->nposition = 0;
	map->nexit = 0;
	map->ncollectable = 0;
	map->nwall = 0;
	map->nspace = 0;
	map->width = 0;
	map->height = 0;
	map->x_exit = 0;
	map->y_exit = 0;
}

int	ft_parse_file(int argc, char *argmap, t_map *map)
{
	int	fd;
	int	len;

	len = ft_strlen(argmap) - 4;
	ft_init_map(map);
	if (argc != 2)
		return (ft_print_e("Invalid number of arguments", 1));
	if (ft_strlen(argmap) <= 4 || ft_strncmp(&argmap[len], ".ber", 4) != 0)
		return (ft_print_e("Invalid file", 1));
	fd = open(argmap, O_RDONLY);
	if (fd < 0)
		return (ft_print_e("File not found", 1));
	return (ft_parse_map(fd, map));
}

int	ft_nlines(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		map->height++;
		line= get_next_line(fd);
		free (line);
	}
	if (map->height == 0)
	{
		ft_printf("%s\n", "Empty map");
		close(fd);
		return (0);
	}
	return (map->height);
}

int	ft_parse_map(int fd, t_map *map)
{
	char	*error;

	error = "Invalid map";
	if (!map)
		return (ft_print_e("Memory error", 1));
	map->map = (char **)malloc(sizeof(char *) * ft_nlines(fd, map));
	if (!map->map)
		return (ft_print_e("Memory failure",1));
	map = ft_cpy_map(fd, map);
	if (map == NULL)
		return (ft_print_e("Empty map", 1));
	if (ft_parse_square(map) != 0)
		return (ft_print_e(error, 1));
	if (ft_parse_closed(map) != 0)
		return (ft_print_e(error, 1));
	if (ft_parse_exit(map) != 0)
		return (ft_print_e(error, 1));
	if (ft_parse_initpos(map) != 0)
		return (ft_print_e(error, 1));
	if (ft_parse_collec(map) != 0)
		return (ft_print_e(error, 1));
	return (0);
}

int	ft_parse_square(t_map *map)
{
	int	i;

	i = 0;
	while ((i < map->height) && map->map[i + 1] != NULL)
	{
		if (ft_strlen(map->map[i]) == ft_strlen(map->map[i]))
			i++;
		else
			return (1);
	}
	map->width = ft_strlen(map->map[i]);
	return (0);
}
