/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:35:58 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/25 03:13:17 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

void	show_xyz(t_mlx win)
{
	int		x0;
	int		y0;
	t_line	x;
	t_line	y;
	t_line	z;

	x0 = win.l / 2;
	y0 = win.w / 2;
	x = line(x0, win.l, y0, y0, WHITE);
	y = line(y0, win.w, x0, x0, BLUE);
	z = line(x0, y0, 0, x0 - y0, GREEN);
	draw_wu_line(win, x);
	//draw_wu_line(win, y);
	draw_vert(win, y);
	draw_wu_line(win, z);
}

int		key(int key)
{
//	printf("%i", win.f);
//	win.f = !win.f;
	if (key == kVK_Escape)
		exit(0);
//	else if (key == kVK_ANSI_0)
//	{
//		if (win.f)
//			show_xyz();
//		else
//			return (0);
//	}
	return (0);
}

t_mlx	window(int w, int l)
{
	t_glist	data;
	int		x;
	int		y;
	int		fd;

	win.f = 0;
	win.w = w;
	win.l = l;
	win.mp = mlx_init();
	win.wp = mlx_new_window(win.mp, w, l, "fdf");
	mlx_key_hook(win.wp, key, (void *)0);
	return (win);
}
