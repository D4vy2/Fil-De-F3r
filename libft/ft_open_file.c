/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:26:44 by dea               #+#    #+#             */
/*   Updated: 2015/06/02 17:19:50 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	ft_open_file(int argc, char **argv, t_env e)
{
	char	**map;
	int		fd;
	int		ret;

	ret = 0;
	if (argc != 2)
	{
		ft_putstr("Usage fdf(): Need one map to run.\n");
		exit(0);
	}
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open() failed\n");
		exit(0);
	}
	map = ft_return_map(fd, ret);
	e.ymax = ft_return_ymax(map);
	e.tab = ft_convert_map(map, e);
	e.xmax = ft_count_points(map[0]);
	ft_check_map(map, &e);
	free(map);
	close(fd);
	return (e);
}
