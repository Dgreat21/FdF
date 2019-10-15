/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:03:49 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/13 19:48:13 by dgreat           ###   ########.fr       */
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
	mlx_pixel_put(win.mp, win.wp, (int)dot.x, (int)dot.y, color);
}

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
			pixel(win, set_dot(x, y), brightness(hue, 1 - fract(y)));//
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
