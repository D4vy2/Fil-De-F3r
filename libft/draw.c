/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 13:52:56 by dea               #+#    #+#             */
/*   Updated: 2015/10/06 15:21:45 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_left(t_env *e)
{
	ft_check_gradient_left(e);
	e->color_swap = (e->tab[e->y][e->x] > 0
			|| e->tab[e->y][e->x - 1] > 0) ? 1 : 0;
	ft_coord_left(e);
	line(e);
	e->color_swap = 0;
	e->invert = 0;
	e->top = 0;
}

void	ft_draw_up(t_env *e)
{
	ft_check_gradient_up(e);
	e->color_swap = (e->tab[e->y][e->x] > 0
			|| e->tab[e->y - 1][e->x] > 0) ? 1 : 0;
	ft_coord_up(e);
	line(e);
	e->color_swap = 0;
	e->invert = 0;
	e->top = 0;
}

void	draw(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	ft_settings(e);
	e->y = 0;
	while (e->y < e->ymax)
	{
		e->x = 0;
		while (e->x < e->xmax)
		{
			ft_init_loop(e);
			if (e->x > 0)
				ft_draw_left(e);
			if (e->y > 0)
				ft_draw_up(e);
			e->x++;
		}
		e->y++;
	}
}
