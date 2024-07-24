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
	{
		close(fd);
		return (NULL);
	}
	while (i < (map->height))
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
	return (map);
}
