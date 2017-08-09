/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:30:37 by dea               #+#    #+#             */
/*   Updated: 2015/06/02 16:51:33 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_return_ymax(char **tab)
{
	int len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

int		ft_count_points(char *s)
{
	int i;
	int points;

	i = 0;
	points = 0;
	while (s[i])
	{
		while (s[i] == ' ' && s[i])
			i++;
		if (s[i] != ' ' && s[i])
		{
			points++;
			while (s[i] != ' ' && s[i])
				i++;
		}
	}
	return (points);
}

int		*ft_convert_atoi(char *s)
{
	int		*tab;
	int		len;
	int		i;
	char	**chartab;

	i = 0;
	len = ft_count_points(s);
	if (NULL == (tab = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	chartab = ft_strsplit(s, ' ');
	while (i < len)
	{
		tab[i] = ft_atoi(chartab[i]);
		i++;
	}
	return (tab);
}

int		**ft_convert_map(char **map, t_env vmax)
{
	int len;
	int i;
	int **tab;
	int **ptr;

	i = 0;
	len = ft_return_ymax(map);
	vmax.ymax = len;
	if (NULL == (tab = (int**)malloc(sizeof(int*) * len)))
		return (NULL);
	ptr = tab;
	while (i < len)
	{
		tab[i] = ft_convert_atoi(map[i]);
		i++;
	}
	tab = ptr;
	return (tab);
}

char	**ft_return_map(int fd, int ret)
{
	char	*line;
	int		len_map;
	char	*save;
	char	**map;
	char	*temp;

	len_map = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		(*line) ? len_map++ : 0;
		if (!save)
			save = ft_strjoin(line, "\n");
		else
		{
			temp = save;
			save = ft_strjoin(save, line);
			save = ft_strjoin(save, "\n");
			free(temp);
		}
	}
	ft_check_ret(ret);
	map = ft_strsplit(save, '\n');
	free(save);
	map[len_map] = NULL;
	return (map);
}
