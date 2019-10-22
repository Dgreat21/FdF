/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:03:49 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/22 23:00:03 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			brightness(t_color hue, float k)
{
	hue.rgb.r = (unsigned char)round((float)hue.rgb.r * k);
	hue.rgb.g = (unsigned char)round((float)hue.rgb.g * k);
	hue.rgb.b = (unsigned char)round((float)hue.rgb.b * k);
	return (hue.mlx);
}

void  		pixel_img(t_mlx *win, t_glist dot)
{
	int  point;

	if ((dot.y > 0) && (dot.y < LENGTH) && (dot.x > 0) && (dot.x < WIDE))
	{
		point = ((int) dot.y * win->lsize) + ((int) dot.x * win->bpp / 8);
		win->data[point] = dot.hue.rgb.b;
		win->data[++point] = dot.hue.rgb.g;
		win->data[++point] = dot.hue.rgb.r;
		win->data[++point] = dot.hue.rgb.a;
	}
}

void		pixel_c(t_mlx win, t_glist dot)
{
	mlx_pixel_put(win.mp, win.wp, (int)dot.x, (int)dot.y, dot.hue.mlx);
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

//int			grad_easy(t_mlx win, float z)//todo func to different coords
//{
//	float			f;
//	t_color			res;
//
//
//	f = perc(win.min_z, win.max_z, z);
//	res.rgb.r = win..rgb.r * (1 - f) + b.rgb.r * f;
//	res.rgb.g = a.rgb.g * (1 - f) + b.rgb.g * f;
//	res.rgb.b = a.rgb.b * (1 - f) + b.rgb.b * f;
//
//	res.mlx = brightness(res, k);
//	return (res.mlx);
//}

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
	res.rgb.r = (unsigned char)(a.rgb.r * (1 - f) + b.rgb.r * f);
	res.rgb.g = (unsigned char)(a.rgb.g * (1 - f) + b.rgb.g * f);
	res.rgb.b = (unsigned char)(a.rgb.b * (1 - f) + b.rgb.b * f);

	res.mlx = brightness(res, k);
	return (res.mlx);
}

void		dot_md(t_mlx *win, t_line l)
{
	pixel_img(win, l.d0);
	pixel_img(win, l.d1);
}

void		drawer(t_mlx *win, t_line l)
{
	float	x;
	float	y;
	int		end;

	l.hue = win->opt.hue;
	x = (l.dir) ? (l.d0.x - 1) : (l.d0.y - 1);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (int)((l.dir) ? (l.d1.x) : (l.d1.y));
	if (l.dir)
		while (++x <= end)
		{
			pixel_img(win, set_dot_c(x, y, brightness(l.d0.hue, 1 - fract(y))));
			pixel_img(win, set_dot_c(x, y + 1, brightness(l.d0.hue, fract(y))));
			y += l.k;
		}
	else
		while (++x <= end)
		{
			pixel_img(win, set_dot_c(y, x, brightness(l.d0.hue, 1 - fract(y))));
			pixel_img(win, set_dot_c(y + 1, x, brightness(l.d0.hue, fract(y))));
			y += l.k;
		}
}

void		brez(t_mlx *win, t_line l)
{
	float	x;
	float	y;
	int		end;

	x = (l.dir) ? (l.d0.x) : (l.d0.y);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (l.dir) ? (l.d1.x) : (l.d1.y);
	--x;
	if (l.dir)
		while (++x <= end)
		{
			pixel_img(win, set_dot_c(x, y, l.d0.hue.mlx));
			y += l.k;
		}
	else
		while (++x <= end)
		{
			pixel_img(win, set_dot_c(y, x, l.d0.hue.mlx));
			y += l.k;
		}
}

void		drawer_grad_old(t_mlx win, t_line l)
{
	float			x;
	float			y;
	int 			end;

	x = (l.dir) ? (l.d0.x - 1) : (l.d0.y - 1);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (l.dir) ? (l.d1.x) : (l.d1.y);
	if (l.dir)
		while (++x <= end)//std
		{

			pixel_c(win, set_dot_c(x, y, grad(1 - fract(y), l, x)));
			pixel_c(win, set_dot_c(x, y + 1, grad(fract(y), l, x)));
			y += l.k;
		}
	else
		while (++x <= end)//invert
		{
			pixel_c(win, set_dot_c(y, x, grad(1 - fract(y), l, x)));
			pixel_c(win, set_dot_c(y + 1, x, grad(fract(y), l, x)));
			y += l.k;
		}
}


void		drawer_grad(t_mlx *win, t_line l)
{
	float			x;
	float			y;
	int 			end;

	x = (l.dir) ? (l.d0.x - 1) : (l.d0.y - 1);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (l.dir) ? (l.d1.x) : (l.d1.y);
	if (l.dir)
		while (++x <= end)//std
		{

			pixel_img(win, set_dot_c(x, y, grad(1 - fract(y), l, x)));
			pixel_img(win, set_dot_c(x, y + 1, grad(fract(y), l, x)));
			y += l.k;
		}
	else
		while (++x <= end)//invert
		{
			pixel_img(win, set_dot_c(y, x, grad(1 - fract(y), l, x)));
			pixel_img(win, set_dot_c(y + 1, x, grad(fract(y), l, x)));
			y += l.k;
		}
}
