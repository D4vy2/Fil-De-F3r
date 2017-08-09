/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_expose_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 19:10:40 by dea               #+#    #+#             */
/*   Updated: 2015/06/02 18:04:57 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_settings(t_env *e)
{
	char *s2;
	char *s3;

	s2 = "ZOOM   : [+]/[-] or [@]/[!] (from top)";
	s3 = "HEIGHT : [u]/[d] or [1]/[0] (from keypad)";
	mlx_string_put(e->mlx, e->win, 25, 20, 0xFFFFFF, "MOVE   :  Arrows");
	mlx_string_put(e->mlx, e->win, 25, 38, 0xFFFFFF, s2);
	mlx_string_put(e->mlx, e->win, 25, 56, 0xFFFFFF, s3);
	mlx_string_put(e->mlx, e->win, 25, 74, 0xFFFFFF, "WIDTH  : [)][(]");
	mlx_string_put(e->mlx, e->win, 25, 92, 0xFFFFFF, "LENGHT : [=][_]");
	mlx_string_put(e->mlx, e->win, 25, 110, 0xFFFFFF, "COLOR  : R,Y,B,G,W");
}

int		ft_convert_iso_x(t_env *e)
{
	int f_x;

	f_x = e->cst1 * e->x1 - e->cst2 * e->y1 + e->mrg_x;
	return (f_x);
}

int		ft_convert_iso_y(t_env *e)
{
	int f_y;

	f_y = -e->tab[e->y][e->x] + e->cst1 / 2 * e->x1
		+ e->cst2 / 2 * e->y1 + e->mrg_y;
	return (f_y);
}

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}
