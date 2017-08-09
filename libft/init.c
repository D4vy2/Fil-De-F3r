/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 11:15:31 by dea               #+#    #+#             */
/*   Updated: 2015/06/02 19:09:35 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_coord_left(t_env *e)
{
	e->x2 = (e->x - 1) * e->esp;
	e->f_x2 = e->cst1 * e->x2 - e->cst2 * e->y1 + e->mrg_x;
}

void	ft_coord_up(t_env *e)
{
	e->x2 = e->x1;
	e->y2 = (e->y - 1) * e->esp;
	e->f_x2 = e->cst1 * e->x2 - e->cst2 * e->y2 + e->mrg_x;
	e->f_y2 = e->cst1 / 2 * e->x2 + e->cst2 / 2 * e->y2;
	e->f_y2 = e->f_y2 + (-e->tab[e->y - 1][e->x]) + e->mrg_y;
}

void	ft_init(t_env *e)
{
	e->lenght = 1500;
	e->width = 1000;
	e->x = 0;
	e->y = 0;
	e->x1 = 0;
	e->y1 = 0;
	e->x2 = 0;
	e->y2 = 0;
	e->f_x1 = e->cst1 * e->x1 - e->cst2 * e->y1 + e->mrg_x;
	e->f_y1 = -e->tab[e->y][e->x] + e->cst1 / 2 * e->x1 + e->cst2 / 2 * e->y1;
	e->f_y1 += e->mrg_y;
	e->f_x2 = 0;
	e->f_y2 = 0;
	e->cst1 = 0.5;
	e->cst2 = 0.5;
	e->esp = e->width / 15;
	e->mrg_x = e->lenght / 2.5;
	e->mrg_y = e->width / 3;
	e->color1 = BLUE;
	e->color2 = PINK;
	e->color3 = e->color2;
	e->invert = 0;
	e->top = 0;
}

void	ft_init_loop(t_env *e)
{
	e->x1 = e->x * e->esp;
	e->y1 = e->y * e->esp;
	e->f_y2 = e->f_y1;
	e->f_x1 = ft_convert_iso_x(e);
	e->f_y1 = ft_convert_iso_y(e);
}
