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

int	ft_parse_file(int argc, char **argmap, t_map *map)
{
	int	fd;
	int	len;
	int	lenfinal;

	lenfinal = ft_strlen(argmap[1]) - 4;
	len = ft_strlen(argmap[1]);
	ft_init_map(map);
	if (argc != 2)
		return (ft_msg_e("Invalid number of arguments", 1));
	if (len <= 4 || ft_strncmp(&argmap[1][lenfinal], ".ber", 4) != 0)
		return (ft_msg_e("Invalid file", 1));
	fd = open(argmap[1], O_RDONLY);
	if (fd < 0)
		return (ft_msg_e("File not found", 1));
	return (ft_parse_map(fd, map));
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

int	ft_parse_map(int fd, t_map *map)
{
	char	*error;

	error = "Invalid map";
	if (!map)
		return (ft_msg_e("Memory error", 1));
	map->map = (char **)malloc(sizeof(char *) * ft_nlines(fd, map));
	if (!map->map)
		return (ft_msg_fd("Memory failure", 1, fd));
	map = ft_cpy_map(fd, map);
	if (map == NULL)
		return (ft_print_error("Empty map", 1));
	if (ft_parse_square(map) != 0)
		return (ft_print_error(error, 1));
	if (ft_parse_closed(map) != 0)
		return (ft_print_error(error, 1));
	if (ft_parse_c(map) != 0)
		return (ft_print_error(error, 1));
	return (0);
}
