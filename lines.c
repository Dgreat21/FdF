/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 03:26:25 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/25 06:09:50 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_vert(t_mlx win, t_line l)
{
	int y;

	y = l.y0 - 1;
	while (++y < l.y1)
		mlx_pixel_put(win.mp, win.wp, l.x0, y, l.color);
}

void	func(float i, float *f, float k)//f -- зависимая от
{
	*f = k * i;
}


//void	draw_mline(t_mlx win, t_line l)
//{
//	float	k;
//	int		i;
//
//
//	k = (float)((l.y1 - l.y0) / (l.x1 - l.x0));
//	if ((l.y1 - l.y0) < (l.x1 - l.x0))
//	{
//		i = l.y0 - 1;
//		while (++i < l.y1)
//		{
//			mlx_pixel_put()
//		}
//	}
//}