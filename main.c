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
	int		error;

	if (!argv)
		return(ft_print_e("Map doesn't exist", 1));
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		perror ("Memory failure");
	error = ft_parse_file(argc, argv, map);
}