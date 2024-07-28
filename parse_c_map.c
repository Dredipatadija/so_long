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

static void	ft_parse_closed2(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map->height)
	{
		if (map->map[j][i] != '1')
			ft_msg_efree("Map is not closed", map->map);
		j++;
	}
	while (i < map->width)
	{
		if (map->map[j - 1][i] != '1')
			ft_msg_efree("Map is not closed", map->map);
		i++;
	}
}

void	ft_parse_closed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->width)
	{
		if (map->map[j][i] != '1')
			ft_msg_efree("Map is not closed", map->map);
		i++;
	}
	while (j < map->height)
	{
		if (map->map[j][i - 1] != '1')
			ft_msg_efree("Map is not closed", map->map);
		j++;
	}
	ft_parse_closed2(map);
}

static void	ft_parse_c2(t_map *map)
{
	if (map->nposition != 1)
			ft_msg_efree("Wrong initial map position", map->map);
	if (map->nexit != 1)
			ft_msg_efree("Wrong initial map position", map->map);
	if (map->ncollectable < 1)
			ft_msg_efree("Wrong initial map position", map->map);
}

void	ft_parse_c(t_map *map)
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
			{
				map->player.x = i;
				map->player.y = j;
				map->nposition++;
			}
			if (map->map[j][i] == 'E')
				map->nexit++;
			if (map->map[j][i] == 'C')
				map->ncollectable++;
			i++;
		}
		j++;
	}
	ft_parse_c2(map);
}
