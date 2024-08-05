/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:15:43 by arenilla          #+#    #+#             */
/*   Updated: 2024/07/25 16:15:50 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(t_map **map, int nl)
{
	(*map)->nposition = 0;
	(*map)->nexit = 0;
	(*map)->ncollectable = 0;
	(*map)->width = 0;
	(*map)->height = 0;
	(*map)->x_exit = -1;
	(*map)->y_exit = -1;
	(*map)->map = (char **)malloc(sizeof(char *) * (nl + 1));
	if (!(*map)->map)
		ft_msg_error("Memory allocation failed for map");
}

void	ft_init_player(t_map *map)
{
	map->player.steps = 0;
	map->player.coin = 0;
	ft_find_position(map);
}
