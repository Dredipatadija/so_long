/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:58:56 by arenilla          #+#    #+#             */
/*   Updated: 2024/07/24 11:58:57 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*ft_cpy_map(int fd, t_map *map)
{
	int		i;

	i = 0;
	if (map->height == 0)
		return (NULL);
	while (i < (map->height))
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
	return (map);
}

int	ft_nlines(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		map->height++;
		line = get_next_line(fd);
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

void	ft_find_exit(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (map->map[j] != NULL)
	{
		while (map->map[j][i] != '\0')
		{
			if (map->map[j][i] == 'E')
			{
				map->map[j][i] = '0';
				break ;
			}
			i++;
		}
		j++;
	}
	map->x_exit = i;
	map->y_exit = j;
}

void	ft_find_position(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (map->map[j] != NULL)
	{
		while (map->map[j][i] != '\0')
		{
			if (map->map[j][i] == 'P')
				break ;
			i++;
		}
		j++;
	}
	map->player.x = i;
	map->player.y = j;
}