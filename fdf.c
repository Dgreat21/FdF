/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:03:49 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/25 09:06:48 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


//void	draw_vert(t_mlx win, t_line l)
//{
//	int y;
//
//	y = l.y0 - 1;
//	while (++y < l.y1)
//		mlx_pixel_put(win.mp, win.wp, l.x0, y, l.color);
//void	draw(t_line l)
//{
//	grad = dy / dx;//k
//	y = l.y0 + grad;
//	x = l.x0;
//	while (++x <= l.x1 - 1)
//	{
//		mlx_pixel_put(win.mp, win.wp, x, (int) y, brightness(l.color, 1 - fract(y)));
//		mlx_pixel_put(win.mp, win.wp, x, (int) y + 1, brightness(l.color, fract(y)));
//		y += grad;
//	}
//}
//

void	draw(t_mlx win, float f0, float f1, float i0, float i1)
{
	float	df;
	float	di;
	float	k;
	float	f;
	int		i;

	df = f1 - f0;
	di = i1 - i0;
	k = df / di;
	f = f0 + k;
	i = (int)i0;
	while (++i <= i1 - 1)
	{
		mlx_pixel_put(win.mp, win.wp, i, (int) f, brightness(color, 1 - fract(f)));
		mlx_pixel_put(win.mp, win.wp, i, (int) f + 1, brightness(l.color, fract(f)));
		f += grad;
	}
}

t_line	line(int x0, int x1, int y0, int y1, int color)
{
	t_line l;

	l.color = color;
	l.x0 = (float)x0;
	l.x1 = (float)x1;
	l.y0 = (float)y0;
	l.y1 = (float)y1;
	l.dx = l.x1 - l.x0;
	l.dy = l.y1 - l.y0;
	if (y1 - y0 > x1 - x0)
	{
		l.k = dx / dy;
		l.i = &l.y0;
	}
	else
		l.k = l.dy / l.dx;
	return (l);
}

int		brightness(int color, float k)
{
	int	r, g, b, tail, res;

	r = R & color;
	g = G & color;
	b = B & color;

	r /= 65536;
	g /= 256;
	r = round((float)r * k);
	g = round((float)g * k);
	b = round((float)b * k);
	r *= 65536;
	g *= 256;

	res = r | g | b;
	return (res);
}

float	fract(float y)
{
	return (y - (int)y);
}

void	draw_wu_line(t_mlx win, t_line l)//todo NORM
{
	short	f;
	float	dx;
	float	dy;
	float	x;
	float	y;
	float	grad;

	if (l.x0 > l.x1)
	{
		ft_fswap(&l.x0, &l.x1);
		ft_fswap(&l.y0, &l.y1);
	}
	if (l.dx >= l.dy)
	{
		grad = dy / dx;
		y = l.y0 + grad;
		x = l.x0;
		while (++x <= l.x1 - 1)
		{
			mlx_pixel_put(win.mp, win.wp, x, (int)y, brightness(l.color, 1 - fract(y)));
			mlx_pixel_put(win.mp, win.wp, x, (int)y + 1, brightness(l.color, fract(y)));
			y += grad;
		}
	}
	else
	{
		grad = dx / dy;
		x = l.x0 + grad;
		y = l.y0;
		while (++y <= l.y1 - 1)
		{
			mlx_pixel_put(win.mp, win.wp, (int)x,  y, brightness(l.color, 1 - fract(x)));
			mlx_pixel_put(win.mp, win.wp, (int)x + 1, y, brightness(l.color, fract(x)));
			x += grad;
		}
	}
}


//void	check_line_data(t_line *line)
//{
//	t_line	l;
//	int		f;
//
//
//	l = line;
//	if (l.x0 > l.x1)
//	{
//		ft_swap(&l.x0, &l.x1);
//		ft_swap(&l.y0, &l.y1);
//	}
//}


void	draw_my_line(t_mlx win, t_line l)
{
	float	y;
	float	k;
	int		x;


	check_line_data(&l);
	if (l.x0 == l.x1)
		draw_vert(win, l);
	else
}

int		main(void)
{
	float	var;
	t_mlx	win;
	int		x, color;
	t_line	l;

	x = 10;
	win = window(1000, 1000);
	color = WHITE;
	l = line(1000, 200, 10, 1500, color);
	draw_vert(win, l);
	//draw_wu_line(win, l);
	mlx_loop(win.mp);
	return (0);
}


