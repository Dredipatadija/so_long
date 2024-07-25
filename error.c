/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmsg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:58:36 by arenilla          #+#    #+#             */
/*   Updated: 2024/07/24 11:58:37 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_msg_error(char *str, int n)
{
	ft_printf("%s\n", str);
	return (n);
}

int	ft_msg_fd(char *str, int n, int fd)
{
	ft_printf("%s\n", str);
	close(fd);
	return (n);
}