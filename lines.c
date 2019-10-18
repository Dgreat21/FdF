/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 03:26:25 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/18 05:47:14 by dgreat           ###   ########.fr       */
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
	return (set_dot(x, y));
}

//t_glist

void		ft_foreach(t_mlx win, t_glist **tab, void (*f)(char *, t_glist))
{
	int		i;
	int		j;

	i = -1;
	while (++i < win.map.y)
	{
		j = -1;
		while (++j < win.map.x)
		{
			(*f)(ft_itoa(i * win.map.x + j), tab[i][j]);
		}
		//error_notice("THE EnD");
	}
}

//пасхальная карта
void	ft_foreach_dot(t_mlx win, t_glist **tab, t_glist (*f)(t_mlx , t_glist))
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
			drawer_grad(win, line(b, a));
		}
		drawer_grad(win, line(f(win, tab[i][j]), f(win, tab[i + 1][j])));
	}
}

void		draw_map(t_mlx win, t_glist **map)
{
//	t_glist a, b;
//
//	ft_foreach(win, map, vardot);
//	a = set_dot(100, 200);
//	a.color.mlx = 0x00ff00;
//	b = set_dot(500, 700);
//	b.color.mlx = 0x0000ff;
//	drawer_grad(win, line(a, b));
	create_proj(win, map, drw_dt_iso);
//	ft_foreach_dot(win, map, drw_dt_iso);
}
