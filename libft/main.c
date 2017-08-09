/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:26:49 by dea               #+#    #+#             */
/*   Updated: 2015/06/02 19:03:52 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_env	e;

	e = ft_open_file(argc, argv, e);
	e.mlx = mlx_init();
	ft_init(&e);
	e.win = mlx_new_window(e.mlx, e.lenght, e.width, "fdf");
	mlx_key_hook(e.win, manage_key, &e);
	mlx_mouse_hook(e.win, manage_mouse, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
