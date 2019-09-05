/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:03:49 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/05 23:36:02 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}

void brighteness(int color, float k)
{

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
	for (x <= x1 - 1)
	{//интенсивность и цвет
		DrawPoint(steep, x, (int)y, 1 - (y - (int)y));
		mlx_pixel_put(win.mp, win.wp, x, (int)y, color)
		DrawPoint(steep, x, (int)y + 1, y - (int)y);
		y += gradient;
		x++
	}
}
