/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 16:47:40 by dea               #+#    #+#             */
/*   Updated: 2015/06/02 17:50:06 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_ret(int ret)
{
	if (ret == -1)
	{
		perror("argv[1]");
		exit(0);
	}
}

void	ft_check_map(char **map, t_env *e)
{
	int i;
	int nbr;

	i = 0;
	nbr = ft_count_points(map[i]);
	while (i < e->ymax)
	{
		ft_count_points(map[i]);
		if (nbr != ft_count_points(map[i]))
		{
			ft_putstr("Invalid: Map not well formatted.\n");
			exit(0);
		}
		i++;
	}
}
