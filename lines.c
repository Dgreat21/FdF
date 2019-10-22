/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 03:26:25 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/22 22:24:52 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//to dimetry

t_glist		drw_dt_dim(t_mlx win, t_glist dot)
{
	float	x;
	float	y;


	dot.x = (dot.x - win.map.x / 2) * win.scale;
	dot.y = (dot.y - win.map.y / 2) * win.scale;
	dot.z *= win.scale;
	x = win.mid[X] + dot.x - dot.y * cos(PI / 4);
	y = win.mid[Y] - dot.z + dot.y * cos(PI / 4);
	return (set_dot(x, y));
}

//to isometry .. еще надо сделать не dot_mode

t_glist		drw_dt_iso(t_mlx win, t_glist dot)
{
	float	x;
	float	y;

	dot.x = (dot.x - win.map.x / 2) * win.scale;
	dot.y = (dot.y - win.map.y / 2) * win.scale;
	dot.z *= win.scale;
	x = win.mid[X] + (dot.x - dot.y) * cos(PI / 6);
	y = win.mid[Y] - dot.z + (dot.x + dot.y) * cos(PI / 3);
	return (set_dot_c(x, y, dot.hue.mlx));
}

//t_glist

void		ft_foreach(t_mlx win, t_glist **tab, void (*f)(char *, t_glist))
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	while (++i < win.map.y)
	{
		j = -1;
		while (++j < win.map.x && tab[i][j].hue.mlx > 0)
		{
			str = ft_strjoin(ft_itoa(i), ":");
			(*f)(ft_strjoin(str, ft_itoa(j)), tab[i][j]);
		}
		//error_notice("THE EnD");
	}
}

void		ft_foreach_a(t_mlx win, t_glist **tab, void (*f)(t_mlx, t_glist))
{
	int		i;
	int		j;

	i = -1;
	while (++i < win.map.y)
	{
		j = -1;
		while (++j < win.map.x && tab[i][j].hue.mlx > 0)
			(*f)(win, tab[i][j]);
	}
}

//void		create_proj(t_mlx win, t_glist **tab,
//		t_glist (*f)(t_mlx, t_glist), void (*draw)(t_mlx, t_line))
//{
//	int		i;
//	int		j;
//	t_glist	a;
//	t_glist	b;
//
//	i = -1;
//	while (++i < win.map.y - 1)
//	{
//		j = -1;
//		while (++j < win.map.x - 1 && tab[i][j].hue.mlx > 0)
//		{
//			a = f(win, tab[i][j]);
//			b = f(win, tab[i][j + 1]);
//			draw(win, line(a, b));
//			b = f(win, tab[i + 1][j]);
//			draw(win, line(a, b));
//			a = f(win, tab[i + 1][j + 1]);
//			draw(win, line(a, b));
//		}
//		draw(win, line(f(win, tab[i][j]), f(win, tab[i + 1][j])));
//	}
//}

void		create_proj_new(t_mlx *win, t_glist **tab,
						t_glist (*f)(t_mlx, t_glist), void (*draw)(t_mlx*, t_line))
{
	int		i;
	int		j;
	t_glist	a;
	t_glist	b;

	i = -1;
	while (++i < win->map.y - 1)
	{
		j = -1;
		while (++j < win->map.x - 1 && tab[i][j].hue.mlx > 0)
		{
			a = f(*win, tab[i][j]);
			b = f(*win, tab[i][j + 1]);
			draw(win, line(a, b));
			b = f(*win, tab[i + 1][j]);
			draw(win, line(a, b));
			a = f(*win, tab[i + 1][j + 1]);
			draw(win, line(a, b));
		}
		draw(win, line(f(*win, tab[i][j]), f(*win, tab[i + 1][j])));
	}
}

void		vard(char *s, t_glist a)
{
	endl();
	ft_putstr(s);
	ft_putchar('(');
	ft_putnbr(a.x);
	ft_putchar(';');
	ft_putnbr(a.y);
	ft_putchar(';');
	ft_putnbr(a.z);
	ft_putchar(';');
	ft_putnbr_base(a.hue.mlx, 16, 1);
	ft_putchar(')');
	endl();
}

void		draw_map(t_mlx *win, t_glist **map)
{
//	t_glist a, b;
//	t_color c, d;
	const void	*f ;//= (win->opt.axis) ? (drw_dt_iso) : (drw_dt_dim);
	const void	*draw;

//	if (win->opt.dt_mode)
//		draw = dot_md;
//	else if (!win->opt.grad)
//		draw = drawer;
//	else
//		draw = (win->opt.grad > 0) ? (drawer_grad) : (brez);
//	ft_foreach(win, map, vard);
	f = drw_dt_iso;
	draw = drawer_grad;
	create_proj_new(win, map, f, draw);
//	ft_foreach_dot(win, map, drw_dt_iso);
}
