/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:58:07 by arenilla          #+#    #+#             */
/*   Updated: 2024/07/24 11:58:12 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		ft_msg_error("You must run so_long with a map");
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		ft_msg_error("Memory allocation failed for t_map at the beginning");
	ft_parse_file(argv, map);
	ft_init_game(&map);
	return (0);
}
