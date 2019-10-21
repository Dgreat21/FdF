/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 03:26:25 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/21 06:13:02 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//to dimetry

t_glist		drw_dt_dim(t_mlx win, t_glist dot)
{
	float	x;
	float	y;

	x = win.mid[X] + dot.x - dot.y * cos(PI / 4);
	y = win.mid[Y] - dot.z + dot.y * cos(PI / 4);
	return (set_dot(x, y));
}

//to isometry .. еще надо сделать не dot_mode

t_glist		drw_dt_iso(t_mlx win, t_glist dot)
{
	float	x;
	float	y;

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
		while (++j < win.map.x)
		{
			str = ft_strjoin(ft_itoa(i), ":");
			(*f)(ft_strjoin(str, ft_itoa(j)), tab[i][j]);
		}
		//error_notice("THE EnD");
	}
}

//void		ft_foreach_color(t_mlx win, t_glist **tab, void (*f)(t_mlx, ))
//{
//	int		i;
//	int		j;
//
//	i = -1;
//	while (++i < win.map.y)
//	{
//		j = -1;
//		while (++j < win.map.x)
//		{
//			(*f)(ft_itoa(i * win.map.x + j), tab[i][j]);
//		}
//		//error_notice("THE EnD");
//	}
//}

//пасхальная карта
void	ft_foreach_dot(t_mlx win, t_glist **tab, t_glist (*f)(t_mlx, t_glist))
{
	int		i;
	int		j;

	i = -1;
	while (++i < win.map.y)
	{
		j = -1;
		while (++j < win.map.x)
		{
			if (tab[i][j].z > 0)
				pixel(win, (*f)(win, tab[i][j]), WHITE);
//			else
//				pixel(win, (*f)(win, tab[i][j]), BLUE);
		}
	}
}


//Создание сетки
void		create_proj(t_mlx win, t_glist **tab, t_glist (*f)(t_mlx, t_glist))
{
	int		i;
	int		j;
	t_glist	a;
	t_glist	b;

	i = -1;
	while (++i < win.map.y - 1)
	{
		j = -1;
		while (++j < win.map.x - 1)
		{
			a = f(win, tab[i][j]);
			b = f(win, tab[i][j + 1]);
			drawer(win, line(a, b));
			b = f(win, tab[i + 1][j]);
			drawer(win, line(a, b));
			a = f(win, tab[i + 1][j + 1]);
			drawer(win, line(b, a));
		}
		drawer(win, line(f(win, tab[i][j]), f(win, tab[i + 1][j])));
	}
}

void		create_proj_grad(t_mlx win, t_glist **tab, t_glist (*f)(t_mlx, t_glist))
{
	int		i;
	int		j;
	t_glist	a;
	t_glist	b;

	i = -1;
	while (++i < win.map.y - 1)
	{
		j = -1;
		while (++j < win.map.x - 1)
		{
			a = f(win, tab[i][j]);
			b = f(win, tab[i][j + 1]);
			drawer_grad(win, line(a, b));

			b = f(win, tab[i + 1][j]);
			drawer_grad(win, line(a, b));

			a = f(win, tab[i + 1][j + 1]);
			drawer_grad(win, line(a, b));
//			error_notice("Debug");
		}
		drawer_grad(win, line(f(win, tab[i][j]), f(win, tab[i + 1][j])));
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
void		draw_map(t_mlx win, t_glist **map)
{
//	t_glist a, b;
//	t_color c, d;
////
////	ft_foreach(win, map, vard);
//	d.mlx = 0x0000ff;
//	c.mlx = 0x00ff00;
//	a = set_dot_c(100, 200, c);
//	b = set_dot_c(500, 300, d);
//	drawer_grad(win, line(a, b));
//	a = set_dot(110, 210);
//	b = set_dot(510, 310);
//	drawer(win, line(a, b));
	vardump("grad", win.opt.grad);
//	win.opt.grad = 1;
//	if (win.opt.grad)
		create_proj_grad(win, map, drw_dt_iso);
//	else
//		create_proj(win, map, drw_dt_iso);
//	ft_foreach_dot(win, map, drw_dt_iso);
}
