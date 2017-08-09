/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 11:41:15 by dea               #+#    #+#             */
/*   Updated: 2015/06/02 11:41:21 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_choose_color_dx(int i, t_env *e)
{
	e->col1 = e->dx / 3;
	e->col2 = e->dx / 2;
	e->col3 = e->dx / 10 * 8;
	ft_check_invert(i, e);
}

void	ft_check_invert(int i, t_env *e)
{
	if (e->invert == 0)
	{
		e->color2 = (i < e->col1) ? PINK : 0;
		if (i >= e->col1)
			e->color2 = PINK2;
		if (i >= e->col2)
			e->color2 = PINK3;
		if (i >= e->col3)
			e->color2 = PINK4;
	}
	else
	{
		e->color2 = (i < e->col1) ? PINK4 : 0;
		if (i >= e->col1)
			e->color2 = PINK3;
		if (i >= e->col2)
			e->color2 = PINK2;
		if (i >= e->col3)
			e->color2 = PINK;
	}
}

void	ft_choose_color_dy(int i, t_env *e)
{
	e->col1 = e->dy / 3;
	e->col2 = e->dy / 2;
	e->col3 = e->dy / 10 * 8;
	ft_check_invert(i, e);
}

void	ft_check_gradient_left(t_env *e)
{
	if (e->tab[e->y][e->x - 1] < e->tab[e->y][e->x])
		e->invert = 1;
	if (e->tab[e->y][e->x - 1] == e->tab[e->y][e->x] && e->tab[e->y][e->x] != 0)
		e->top = 1;
}

void	ft_check_gradient_up(t_env *e)
{
	if (e->tab[e->y - 1][e->x] < e->tab[e->y][e->x])
		e->invert = 1;
	if (e->tab[e->y - 1][e->x] == e->tab[e->y][e->x] && e->tab[e->y][e->x] != 0)
		e->top = 1;
}
