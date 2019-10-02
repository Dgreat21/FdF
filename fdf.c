/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:03:49 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/02 11:09:18 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define MOVE 6000

int		brightness0(int color, float k)
{
	int	r;
	int	g;
	int	b;
	int	res;

	r = R & color;
	g = G & color;
	b = B & color;
	r = r >> 16;
	g = g >> 8;
	r = round((float)r * k);
	g = round((float)g * k);
	b = round((float)b * k);
	r = r << 16;
	g = g << 8;
	res = r | g | b;
	return (res);
}

int		brightness(t_color hue, float k)
{
	hue.rgb.r = round((float)hue.rgb.r * k);
	hue.rgb.g = round((float)hue.rgb.g * k);
	hue.rgb.b = round((float)hue.rgb.b * k);

	return (hue.mlx);
}

void	pixel(t_mlx win, t_glist dot, int color)
{
	mlx_pixel_put(win.mp, win.wp, (int)dot.x, (int)dot.y, color);
}

//void	drawer0(t_mlx win, t_line l)
//{
//	float	x;
//	float	y;
//	int		end;
//	int		hue;
//
//	hue = l.color;
//	x = (l.dir) ? (l.d0.x) : (l.d0.y);
//	y = (l.dir) ? (l.d0.y) : (l.d0.x);
//	end = (l.dir) ? (l.d1.x) : (l.d1.y);
//	--x;
//	if (l.dir)
//		while (++x <= end)
//		{
//			pixel(win, set_dot(x, y), brightness(hue, 1 - fract(y)));
//			pixel(win, set_dot(x, y + 1), brightness(hue, fract(y)));
//			y += l.k;
//		}
//	else
//		while (++x <= end)// часть которая работает по y
//		{
//			pixel(win, set_dot(y, x), brightness(hue, 1 - fract(x)));
//			pixel(win, set_dot(y + 1, x), brightness(hue, fract(x)));
//			y += l.k;
//		}
//}

void	drawer(t_mlx win, t_line l)
{
	float	x;
	float	y;
	int		end;
	t_color	hue;

	hue.mlx = l.color;
	x = (l.dir) ? (l.d0.x) : (l.d0.y);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (l.dir) ? (l.d1.x) : (l.d1.y);
	--x;
	if (l.dir)
		while (++x <= end)
		{
			pixel(win, set_dot(x, y), brightness(hue, 1 - fract(y)));
			pixel(win, set_dot(x, y + 1), brightness(hue, fract(y)));
			y += l.k;
		}
	else
		while (++x <= end)
		{
			pixel(win, set_dot(y, x), brightness(hue, 1 - fract(x)));
			pixel(win, set_dot(y + 1, x), brightness(hue, fract(x)));
			y += l.k;
		}
}

void show_x(t_mlx win, t_glist o)
{
	t_line x1, x2;
	x1 = line(set_dot(o.x + MOVE, o.y), set_dot(o.x + 100, o.y), WHITE);
	x2 = line(set_dot(o.x - MOVE, o.y), set_dot(o.x - 100, o.y), YELLOW);
	drawer(win, x1);
	drawer(win, x2);
}

void show_y(t_mlx win, t_glist o)
{
	t_line y1, y2;
	y1 = line(set_dot(o.x, o.y + MOVE), set_dot(o.x, o.y + 100), GREEN);
	y2 = line(set_dot(o.x, o.y - MOVE), set_dot(o.x, o.y - 100), BLUE);
	drawer(win, y1);
	drawer(win, y2);
}

void show_a(t_mlx win, t_glist o)
{
	t_line a1, a2, a3;
	a1 = line(set_dot(o.x - MOVE, o.y - MOVE), set_dot(o.x - 200, o.y - 100), AQUA);
	a2 = line(set_dot(o.x - MOVE, o.y - MOVE), set_dot(o.x - 100, o.y - 100), FUCHSIA);
	a3 = line(set_dot(o.x - MOVE, o.y - MOVE), set_dot(o.x - 100, o.y - 200), OLIVE);
	drawer(win, a1);
	drawer(win, a2);
	drawer(win, a3);
}

void show_b(t_mlx win, t_glist o)
{
	t_line b1, b2, b3;
	b1 = line(set_dot(o.x + MOVE, o.y - MOVE), set_dot(o.x + 200, o.y - 100), RED);
	b2 = line(set_dot(o.x + MOVE, o.y - MOVE), set_dot(o.x + 100, o.y - 100), MAROON);
	b3 = line(set_dot(o.x + MOVE, o.y - MOVE), set_dot(o.x + 100, o.y - 200), TEAL);
	drawer(win, b1);
	drawer(win, b2);
	drawer(win, b3);
}

void show_c(t_mlx win, t_glist o)
{
	t_line c1, c2, c3;
	c1 = line(set_dot(o.x + MOVE, o.y + MOVE), set_dot(o.x + 200, o.y + 100), AQUA);
	c2 = line(set_dot(o.x + MOVE, o.y + MOVE), set_dot(o.x + 100, o.y + 100), FUCHSIA);
	c3 = line(set_dot(o.x + MOVE, o.y + MOVE), set_dot(o.x + 100, o.y + 200), OLIVE);
	drawer(win, c1);
	drawer(win, c2);
	drawer(win, c3);
}

void show_d(t_mlx win, t_glist o)
{
	t_line d1, d2, d3;
	d1 = line(set_dot(o.x - MOVE, o.y + MOVE), set_dot(o.x - 200, o.y + 100), RED);
	d2 = line(set_dot(o.x - MOVE, o.y + MOVE), set_dot(o.x - 100, o.y + 100), MAROON);
	d3 = line(set_dot(o.x - MOVE, o.y + MOVE), set_dot(o.x - 100, o.y + 200), TEAL);
	drawer(win, d1);
	drawer(win, d2);
	drawer(win, d3);
}

int		main(void)
{
	t_mlx	win;
//	int		color;
//	t_line	l;
	t_glist	o;

	o = set_dot(500, 500);
	win = window(1000, 1000);
	//color = ft_atoi_base(av[1], 16);
	show_x(win, o);
	show_y(win, o);
	show_a(win, o);
	show_b(win, o);
	show_c(win, o);
	show_d(win, o);
	//show_xyz(win);
	mlx_loop(win.mp);
	return (0);
}
