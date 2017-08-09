/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 16:12:21 by dea               #+#    #+#             */
/*   Updated: 2015/05/12 18:38:13 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_readline(char *save)
{
	size_t	len;
	char	*line;

	len = 0;
	while (save[len] != '\n' && save[len] != '\0')
		len++;
	line = ft_strsub(save, 0, len);
	return (line);
}

int		get_next_line(int const fd, char **line)
{
	static char		*save;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if (!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (!save)
			save = ft_strdup(buf);
		else
			save = ft_strjoin(save, buf);
	}
	if ((!save || *save == '\0') && (ret == 0))
		return (0);
	if (*save == '\n')
		save++;
	*line = ft_readline(save);
	while (*save != '\n' && *save != '\0')
		save++;
	save++;
	return (1);
}
