/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:03:49 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/10 03:14:08 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		ft_swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}

int		 brightness(int color, float k)
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

void		draw_wu_line(t_mlx win, t_line l)
{
	short	f;
	float	dx, dy, y, grad;
	int		x;

	f = 0;
	(abs(l.x1-l.x0) < (abs(l.y1-l.y0))) ? f++ : (0);
	if (f)
	{
		ft_swap(&l.x0, &l.y0);
		ft_swap(&l.x1, &l.y1);
	}
	if (l.x0 > l.x1)
	{
		ft_swap(&l.x0, &l.x1);
		ft_swap(&l.y0, &l.y1);
	}
	dx = l.x1 - l.x0;
	dy = l.y1 - l.y0;
	grad = dy / dx;
	y = l.y0 + grad;
	x = l.x0 + 1;
	while (x <= l.x1 - 1)
	{
		mlx_pixel_put(win.mp, win.wp, x, (int)y, brightness(l.color, 1 - (y - (int)y)));
		mlx_pixel_put(win.mp, win.wp, x, (int)y +1, brightness(l.color, y - (int)y));
		y += grad;
		x++;
	}
	
}

t_line	line(int x0, int x1, int y0, int y1, int color)
{
	t_line l;
	l.x0 = x0;
	l.x1 = x1;
	l.y0 = y0;
	l.y1 = y1;
	l.color = color;
	return (l);
}

int		main()
{
	float	var;
	t_mlx	win;
	int		x, color;
	t_line	l;

	x = 10;
	win = window(1000, 1000);
	color = WHITE;
	l = line(1000, 200, 10, 1500, color);
	draw_wu_line(win, l);
	mlx_loop(win.mp);
	return (0);
}
