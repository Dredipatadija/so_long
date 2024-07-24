/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:58:45 by arenilla          #+#    #+#             */
/*   Updated: 2024/07/24 11:58:47 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stddef.h>

typedef struct s_map
{
	int		nposition;
	int		nexit;
	int		ncollectable;
	int		nwall;
	int		nspace;
	int		width;
	int		height;
	int		x_exit;
	int		y_exit;
	char	**map;
}				t_map;

#endif
