/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:03:49 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/16 22:31:01 by dgreat           ###   ########.fr       */
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

//info x - start,
//     y - end,
//     z - cur;

int		grad(short flag, t_glist a, t_glist b, t_glist c)
{
	float		f;
	t_glist		info;
	t_color		res;

	if (flag > 0)//x
		info = set_xyz(a.x, b.x, c.x);
	else if (!flag)//z
		info = set_xyz(a.z, b.z, c.z);
	else//y
		info = set_xyz(a.y, b.y, c.y);
	f = perc(info);
	res.rgb.r = a.color.rgb.r * (1 - f) + b.color.rgb.r * f;
	res.rgb.g = a.color.rgb.g * (1 - f) + b.color.rgb.g * f;
	res.rgb.b = a.color.rgb.b * (1 - f) + b.color.rgb.b * f;
	return (brightness(res, k));
}

void	drawer(t_mlx win, t_line l)
{
	float	x;
	float	y;
	int		end;
	t_color	hue;

	hue.mlx = l.color.mlx;
	x = (l.dir) ? (l.d0.x) : (l.d0.y);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (l.dir) ? (l.d1.x) : (l.d1.y);
	--x;
	if (l.dir)
		while (++x <= end)
		{
			pixel(win, set_dot(x, y), brightness((hue), 1 - fract(y)));//
			pixel(win, set_dot(x, y + 1), brightness(hue, fract(y)));//
			y += l.k;
		}
	else
		while (++x <= end)
		{
			pixel(win, set_dot(y, x), brightness(hue, 1 - fract(x)));//
			pixel(win, set_dot(y + 1, x), brightness(hue, fract(x)));//
			y += l.k;
		}
}

//void	drawer_grad(t_mlx win, t_line l)
//{
//	float x;
//	float y;
//	int end;
//	t_color hue0;
//	t_color hue1;
//
//	hue0 = l.d0.color;
//	hue1 = l.d1.color;
//	x = (l.dir) ? (l.d0.x - 1) : (l.d0.y - 1);
//	y = (l.dir) ? (l.d0.y) : (l.d0.x);
//	end = (l.dir) ? (l.d1.x) : (l.d1.y);
//	if (l.dir)
//		while (++x <= end)//std
//		{
//			pixel(win, set_dot(x, y), grad(l.d0, l.d1, set_xyz(x, y, ));//
//			pixel(win, set_dot(x, y + 1), brightness(hue, fract(y)));//
//			y += l.k;
//		}
//	else
//		while (++x <= end)//invert
//		{
//			pixel(win, set_dot(y, x), brightness(hue, 1 - fract(x)));//
//			pixel(win, set_dot(y + 1, x), brightness(hue, fract(x)));//
//			y += l.k;
//		}
//}
