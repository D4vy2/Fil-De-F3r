/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 18:01:37 by dea               #+#    #+#             */
/*   Updated: 2015/06/02 11:11:21 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_height_more(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while (e->y < e->ymax)
	{
		e->x = 0;
		while (e->x < e->xmax)
		{
			if (e->tab[e->y][e->x] != 0 && e->tab[e->y][e->x] < 150)
				e->tab[e->y][e->x] = e->tab[e->y][e->x] + 5;
			e->x++;
		}
		e->y++;
	}
}

void	ft_height_less(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while (e->y < e->ymax)
	{
		e->x = 0;
		while (e->x < e->xmax)
		{
			if (e->tab[e->y][e->x] != 0 && e->tab[e->y][e->x] > 6)
				e->tab[e->y][e->x] = e->tab[e->y][e->x] - 5;
			e->x++;
		}
		e->y++;
	}
}
