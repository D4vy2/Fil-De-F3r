/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 19:01:09 by dea               #+#    #+#             */
/*   Updated: 2015/06/02 17:43:05 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		manage_mouse(int button, int x, int y, t_env *e)
{
	ft_putstr("mouse: ");
	ft_putnbr(button);
	ft_putstr(" (");
	ft_putnbr(x);
	write(1, ":", 1);
	ft_putnbr(y);
	ft_putstr(")\n");
	button == 5 ? e->esp += 20 : e->esp;
	button == 4 && e->esp > 21 ? e->esp -= 20 : e->esp;
	draw(e);
	return (0);
}

int		manage_key(int keycode, t_env *e)
{
	keycode == 53 ? exit(0) : 0;
	keycode == 124 ? e->mrg_x += 15 : e->mrg_x;
	keycode == 123 ? e->mrg_x -= 15 : e->mrg_x;
	keycode == 125 ? e->mrg_y += 15 : e->mrg_y;
	keycode == 126 ? e->mrg_y -= 15 : e->mrg_y;
	keycode == 69 || keycode == 19 ? e->esp += 3 : e->esp;
	(keycode == 78 || keycode == 18) && e->esp > 3 ? e->esp -= 3 : e->esp;
	keycode == 24 ? e->cst1 += 0.05 : e->cst1;
	keycode == 27 && e->cst1 > 0.05 ? e->cst1 -= 0.05 : e->cst1;
	keycode == 29 ? e->cst2 += 0.05 : e->cst2;
	keycode == 25 && e->cst2 > 0.05 ? e->cst2 -= 0.05 : e->cst2;
	keycode == 83 || keycode == 32 ? ft_height_more(e) : 0;
	keycode == 82 || keycode == 2 ? ft_height_less(e) : 0;
	keycode == 11 ? e->color1 = BLUE : 0;
	keycode == 15 ? e->color1 = RED : 0;
	keycode == 16 ? e->color1 = YELLOW : 0;
	keycode == 13 ? e->color1 = WHITE : 0;
	keycode == 5 ? e->color1 = GREEN : 0;
	draw(e);
	return (0);
}
