/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 03:26:25 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/16 00:00:26 by dgreat           ###   ########.fr       */
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

//void	ft_foreach_dot(t_mlx win, t_glist **tab, t_glist (*f)(t_mlx , t_glist))
//{
//	int		i;
//	int		j;
//
//	i = -1;
//	while (++i < win.map.y)
//	{
//		j = -1;
//		while (++j < win.map.x)
//				pixel(win, (*f)(win, tab[i][j]), COLOR);
//	}
//}

void		create_proj(t_mlx win, t_glist **tab, t_glist (*f)(t_mlx, t_glist))
{
	int		i;
	int		j;
	t_glist	a;
	t_glist	b;
	t_glist	c;

	i = -1;
	while (++i < win.map.y - 1)
	{
		j = -1;
		while (++j < win.map.x - 1)
		{
			a = f(win, tab[i][j]);
			b = f(win, tab[i][j + 1]);
			c = f(win, tab[i + 1][j]);
			drawer(win, line(a, b, WHITE));
			drawer(win, line(a, c, WHITE));
		}
	}
	j = (int)win.map.x - 1;
	a = f(win, tab[i][0]);
	b = f(win, tab[0][j]);
	c = f(win, tab[i][j]);
	drawer(win, line(a, c, WHITE));
	drawer(win, line(b, c, WHITE));
}

void		draw_map(t_mlx win, t_glist **map)
{
//	vardot("test1", map[9][0]);
//	ft_foreach(win, map, vardot);
//	ft_foreach_dot(win, map, drw_dt_iso);
	create_proj(win, map, drw_dt_iso);
	ft_foreach(win, map, vardot);
}
