/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:24:45 by dea               #+#    #+#             */
/*   Updated: 2015/06/02 19:09:36 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <string.h>
# include <ctype.h>
# include <stdio.h>

# define BUFF_SIZE 8
# define RED 0xCC1100
# define YELLOW 0xFFEE93
# define BLUE 0x00868B
# define GREEN 0x88FFC3
# define WHITE 0xFFFFFF
# define PINK 0xFF0066
# define PINK2 0xFF4D94
# define PINK3 0xFF99C2
# define PINK4 0xFFE5F0

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		lenght;
	int		width;
	int		**tab;
	int		ret;
	int		tabmax;
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		f_x1;
	int		f_y1;
	int		f_x2;
	int		f_y2;
	int		xmax;
	int		ymax;
	float	cst1;
	float	cst2;
	int		esp;
	int		mrg_x;
	int		mrg_y;
	int		i;
	int		xinc;
	int		yinc;
	int		dx;
	int		dy;
	int		color_swap;
	int		color1;
	int		color2;
	int		color3;
	int		invert;
	int		top;
	int		col1;
	int		col2;
	int		col3;

}				t_env;

char			*ft_readline(char *save);
int				get_next_line(int const fd, char **line);

void			ft_putchar(char c);
void			ft_putstr(char *s);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);

void			ft_putnbr(int c);

char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);

char			**ft_strsplit(char const *s, char c);

int				ft_return_ymax(char **tab);
int				ft_count_points(char *s);
int				*ft_convert_atoi(char *s);
char			**ft_return_map(int fd, int ret);
int				**ft_convert_map(char **map, t_env vmax);
void			ft_check_ret(int ret);
void			ft_check_map(char **map, t_env *e);

t_env			ft_open_file(int argc, char **argv, t_env e);

void			draw(t_env *e);
void			ft_draw_left(t_env *e);
void			ft_draw_right(t_env *e);
void			ft_settings(t_env *e);
int				ft_convert_iso_x(t_env *e);
int				ft_convert_iso_y(t_env *e);
int				expose_hook(t_env *e);

void			ft_more_vertical(t_env *e, int x1, int y1);
void			ft_more_horizontal(t_env *e, int x1, int y1);
void			line(t_env *e);

int				manage_mouse(int button, int x, int y, t_env *e);
int				manage_key(int keycode, t_env *e);

void			ft_init(t_env *e);
void			ft_init_loop(t_env *e);
void			ft_coord_up(t_env *e);
void			ft_coord_left(t_env *e);

void			ft_height_more(t_env *e);
void			ft_height_less(t_env *e);

void			ft_choose_color_dx(int i, t_env *e);
void			ft_choose_color_dy(int i, t_env *e);
void			ft_check_gradient_left(t_env *e);
void			ft_check_gradient_up(t_env *e);
void			ft_check_invert(int i, t_env *e);
void			ft_color_swap_horizontal(int i, t_env *e, int x1, int y1);
#endif
