/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:35:58 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/10 02:10:52 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

//void	draw_table(t_mlx win, t_glist data, int len, int a, int b)
//{
//	int ca, cb;
//	t_glist	cdata;
//
//	ca = a;
//	cb = b;
//	cdata = data;
//	while (a >= 0)
//	{
//		draw_gline(win, data, len * b);
//		a--;
//		data.y += len;
//	}
//	a = ca;
//	data = cdata;
//	while (b >= 0)
//	{
//		draw_vline(win, data, len * a);
//		b--;
//		data.x += len;
//	}
//}

t_mlx		window(int w, int l)
{
	t_mlx	win;
	t_glist	data;
	int		x, y, fd;

	win.mp = mlx_init();
	win.wp = mlx_new_window(win.mp, w, l, "fdf");
	mlx_key_hook(win.wp, key, (void *)0);
	return (win);
}