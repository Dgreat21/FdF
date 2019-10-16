/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 03:26:25 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/16 20:16:11 by dgreat           ###   ########.fr       */
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
			drawer(win, line(a, b, WHITE));
			b = f(win, tab[i + 1][j]);
			drawer(win, line(a, b, WHITE));
			a = f(win, tab[i + 1][j + 1]);
			drawer(win, line(b, a, WHITE));
		}
		drawer(win, line(f(win, tab[i][j]), f(win, tab[i + 1][j]), WHITE));
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
			drawer(win, line(a, b, WHITE));
			b = f(win, tab[i + 1][j]);
			drawer(win, line(a, b, WHITE));
			a = f(win, tab[i + 1][j + 1]);
			drawer(win, line(b, a, WHITE));
		}
		drawer_grad(win, line(f(win, tab[i][j]), f(win, tab[i + 1][j]), WHITE));
	}
}

void		draw_map(t_mlx win, t_glist **map)
{
//	ft_foreach(win, map, vardot);
//	vardot("test1", map[9][0]);
	create_proj(win, map, drw_dt_iso);
//	ft_foreach_dot(win, map, drw_dt_iso);
}
