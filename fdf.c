/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:03:49 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/21 06:08:12 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			brightness(t_color hue, float k)
{
	hue.rgb.r = round((float)hue.rgb.r * k);
	hue.rgb.g = round((float)hue.rgb.g * k);
	hue.rgb.b = round((float)hue.rgb.b * k);
	return (hue.mlx);
}

void		pixel(t_mlx win, t_glist dot, int hue)
{
	if (dot.hue.mlx > 0)
		mlx_pixel_put(win.mp, win.wp, (int)dot.x, (int)dot.y, hue);
	else
		mlx_pixel_put(win.mp, win.wp, (int)dot.x, (int)dot.y, dot.hue.mlx);
}

float		perc(float start, float end, float cur)
{
	const float d = end - start;

	if (!(d))
		return (1.0);
	else
		return (((cur - start)/ d));
}

//dots x - start,
//     y - end,

//     cur.x - cur;
//     cur.y - k

int			grad(float k, t_line l, float x)
{
	float			f;
	t_color			res;
	const t_color	a = l.d0.hue;
	const t_color	b = l.d1.hue;


	if (l.dir)
		f = perc(l.d0.x, l.d1.x, x);
	else
		f = perc(l.d0.y, l.d1.y, x);
	res.rgb.r = a.rgb.r * (1 - f) + b.rgb.r * f;
	res.rgb.g = a.rgb.g * (1 - f) + b.rgb.g * f;
	res.rgb.b = a.rgb.b * (1 - f) + b.rgb.b * f;

	res.mlx = brightness(res, k);
	return (res.mlx);
}

void		drawer(t_mlx win, t_line l)
{
	float	x;
	float	y;
	int		end;

	l.hue = win.opt.hue;
	x = (l.dir) ? (l.d0.x) : (l.d0.y);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (l.dir) ? (l.d1.x) : (l.d1.y);
	--x;
	if (l.dir)
		while (++x <= end)
		{
			pixel(win, set_dot(x, y), brightness(l.hue, 1 - fract(y)));
			pixel(win, set_dot(x, y + 1), brightness(l.hue, fract(y)));
			y += l.k;
		}
	else
		while (++x <= end)
		{
			pixel(win, set_dot(y, x), brightness(l.hue, 1 - fract(y)));
			pixel(win, set_dot(y + 1, x), brightness(l.hue, fract(y)));
			y += l.k;
		}
}

void		drawer_grad(t_mlx win, t_line l)
{
	float			x;
	float			y;
	int 			end;
	const t_glist	s = (const t_glist)set_dot(l.d0.x, l.d0.x);

	x = (l.dir) ? (l.d0.x - 1) : (l.d0.y - 1);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (l.dir) ? (l.d1.x) : (l.d1.y);
	if (l.dir)
		while (++x <= end)//std
		{

			pixel(win, set_dot(x, y), grad(1 - fract(y), l, x));
			pixel(win, set_dot(x, y + 1), grad(fract(y), l, x));
			y += l.k;
		}
	else
		while (++x <= end)//invert
		{
			pixel(win, set_dot(y, x), grad(1 - fract(y), l, x));
			pixel(win, set_dot(y + 1, x), grad(fract(y), l, x));
			y += l.k;
		}
}
