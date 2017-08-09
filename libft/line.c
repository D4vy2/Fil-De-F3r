/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 18:04:24 by dea               #+#    #+#             */
/*   Updated: 2015/06/02 11:39:57 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color_swap_horizontal(int i, t_env *e, int x1, int y1)
{
	if (e->color_swap == 1)
	{
		if (e->top == 1)
			e->color2 = PINK4;
		else
			ft_choose_color_dx(i, e);
		mlx_pixel_put(e->mlx, e->win, x1, y1, e->color2);
	}
	else
		mlx_pixel_put(e->mlx, e->win, x1, y1, e->color1);
	e->color3 = (e->color3 < e->color2) ? e->color2 : e->color3;
}

void	ft_color_swap_vertical(int i, t_env *e, int x1, int y1)
{
	if (e->color_swap == 1)
	{
		if (e->top == 1)
			e->color2 = PINK4;
		else
			ft_choose_color_dy(i, e);
		mlx_pixel_put(e->mlx, e->win, x1, y1, e->color2);
	}
	else
		mlx_pixel_put(e->mlx, e->win, x1, y1, e->color1);
	e->color3 = (e->color3 < e->color2) ? e->color2 : e->color3;
}

void	ft_more_horizontal(t_env *e, int x1, int y1)
{
	int i;
	int cumul;

	i = 0;
	cumul = e->dx / 2;
	while (++i <= e->dx)
	{
		x1 += e->xinc;
		cumul += e->dy;
		if (cumul >= e->dx)
		{
			cumul -= e->dx;
			y1 += e->yinc;
		}
		ft_color_swap_horizontal(i, e, x1, y1);
	}
	e->color2 = PINK;
}

void	ft_more_vertical(t_env *e, int x1, int y1)
{
	int i;
	int cumul;

	i = 0;
	cumul = e->dy / 2;
	while (++i <= e->dy)
	{
		y1 += e->yinc;
		cumul += e->dx;
		if (cumul >= e->dy)
		{
			cumul -= e->dy;
			x1 += e->xinc;
		}
		ft_color_swap_vertical(i, e, x1, y1);
	}
	e->color2 = PINK;
}

void	line(t_env *e)
{
	int x1;
	int y1;

	x1 = e->f_x1;
	y1 = e->f_y1;
	e->dx = e->f_x2 - e->f_x1;
	e->dy = e->f_y2 - e->f_y1;
	e->xinc = (e->dx > 0) ? 1 : -1;
	e->yinc = (e->dy > 0) ? 1 : -1;
	e->dx = (e->dx < 0) ? -e->dx : e->dx;
	e->dy = (e->dy < 0) ? -e->dy : e->dy;
	mlx_pixel_put(e->mlx, e->win, x1, y1, e->color1);
	if (e->dx > e->dy)
		ft_more_horizontal(e, x1, y1);
	else
		ft_more_vertical(e, x1, y1);
}
