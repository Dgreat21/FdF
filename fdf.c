/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:03:49 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/18 04:48:55 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		brightness(t_color hue, float k)
{
	hue.rgb.r = round((float)hue.rgb.r * k);
	hue.rgb.g = round((float)hue.rgb.g * k);
	hue.rgb.b = round((float)hue.rgb.b * k);
	return (hue.mlx);
}

void	pixel(t_mlx win, t_glist dot, int color)
{
	if (dot.color.mlx > 0)
		mlx_pixel_put(win.mp, win.wp, (int)dot.x, (int)dot.y, color);
	else
		mlx_pixel_put(win.mp, win.wp, (int)dot.x, (int)dot.y, dot.color.mlx);
}

float	perc(t_glist dot)
{
	const float d = dot.y - dot.x;

	if (!(d))
		return (1.0);
	else
		return (((dot.z - dot.x)/ d));
}

//dots x - start,
//     y - end,

//     cur.x - cur;
//     cur.y - k

int		grad(t_glist dots, t_glist cur, t_color a, t_color b)
{
	float		f;
	t_color		res;

	f = perc(set_xyz(dots.x, dots.y, cur.x));
	res.rgb.r = a.rgb.r * (1 - f) + b.rgb.r * f;
	res.rgb.g = a.rgb.g * (1 - f) + b.rgb.g * f;
	res.rgb.b = a.rgb.b * (1 - f) + b.rgb.b * f;
	return (brightness(res, cur.y));
}

void	drawer(t_mlx win, t_line l)
{
	float	x;
	float	y;
	int		end;
	t_color	hue;

	hue = win.opt.color;
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
			pixel(win, set_dot(y, x), brightness(hue, 1 - fract(y)));
			pixel(win, set_dot(y + 1, x), brightness(hue, fract(y)));
			y += l.k;
		}
}

void	drawer_grad(t_mlx win, t_line l)
{
	float x;
	float y;
	int end;

	x = (l.dir) ? (l.d0.x - 1) : (l.d0.y - 1);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (l.dir) ? (l.d1.x) : (l.d1.y);
	if (l.dir)
		while (++x <= end)//std
		{
			pixel(win, set_dot(x, y), grad(set_dot(l.d0.x - 1, end),
					set_dot(x, 1 - fract(y)), l.d0.color, l.d1.color));
			pixel(win, set_dot(x, y + 1), grad(set_dot(l.d0.x - 1, end),
					set_dot(x, 1 - fract(y)), l.d0.color, l.d1.color));
			y += l.k;
		}
	else
		while (++x <= end)//invert
		{
			pixel(win, set_dot(y, x), grad(set_dot(l.d0.y - 1, end),
					set_dot(x, 1 - fract(x)), l.d0.color, l.d1.color));
			pixel(win, set_dot(y + 1, x), grad(set_dot(l.d0.y - 1, end),
					set_dot(x, 1 - fract(x)), l.d0.color, l.d1.color));
			y += l.k;
		}
}
