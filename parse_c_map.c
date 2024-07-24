/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:58:28 by arenilla          #+#    #+#             */
/*   Updated: 2024/07/24 11:58:30 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parse_closed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->width)
	{
		if (map->map[j][i] != '1')
			return (1);
		i++;
	}
	while (j < map->height)
	{
		if (map->map[j][i - 1] != '1')
			return (1);
		j++;
	}
	return (ft_parse_closed2(map));
}

static int	ft_parse_closed2(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map->height)
	{
		if (map->map[j][i] != '1')
			return (1);
		j++;
	}
	while (i < map->width)
	{
		if (map->map[j - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_parse_c(t_map *map)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (map->map[j] != NULL)
	{
		while (map->map[j][i] != '\0')
		{
			if (map->map[j][i] == 'P')
				map->nposition++;
			if (map->map[j][i] == 'E')
				map->nexit++;
			if (map->map[j][i] == 'C')
				map->ncollectable++;
			i++;
		}
		j++;
	}
	return (ft_parse_c2(map));
}

int	ft_parse_c2(t_map *map)
{
	if (map->nposition != 1)
		return (1);
	if (map->nexit != 1)
		return (1);
	if (map->ncollectable < 1)
		return (1);
	return (0);
}
