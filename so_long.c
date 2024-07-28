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

	error = 0;
	if (!argv[1])
		ft_msg_error("Map doesn't exist");
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		ft_msg_error("Memory failure");
	ft_parse_file(argc, argv, map);
	if (error == 1)
		return (1);
	ft_init_mlx(&map);
	return (0);
}
