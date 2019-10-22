/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:35:58 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/22 23:06:28 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

int		key(int key)
{
	if (key == kVK_Escape)
		exit(0);
	return (0);
}

void	options(t_mlx *win)
{
	win->opt.rot = 0;
	win->opt.grad = -1;
	win->opt.grad3 = 0;
	win->opt.xyz = 0;
	win->opt.dt_mode = 0;//dot mode
	win->opt.axis = 1;
	win->opt.hue.mlx = LIME;
	win->scale = 3;
}

t_mlx	window(int w, int l)
{
	t_mlx win;
	
	options(&win);

	win.w = w;
	win.l = l;
	win.mid[X] = w / 2;
	win.mid[Y] = l / 2;
	win.max_z = 0;
	win.min_z = 0;
	win.mp = mlx_init();
	win.wp = mlx_new_window(win.mp, w, l, "fdf");
//	mlx_hook(win.wp, 2, 0L, key_press, (void *)&win);

	if ((win.img = mlx_new_image(win.mp, WIDE, LENGTH)) == NULL)
		error_notice("mlx_new_image error");
	if ((win.data = mlx_get_data_addr(win.img, &win.bpp, &win.lsize, &win.endian)) == NULL)
		error_notice("mlx_get_data_addr error");
	mlx_key_hook(win.wp, key, (void *) 0);
	return (win);
}

//t_mlx	*window_stable(int w, int l)
//{
//	t_mlx	*win;
//	int   bpp;
//	int   lsize;
//	int   endian;
//
//	if ((win = (t_mlx *)malloc(sizeof(t_mlx))) == NULL)
//		error_notice("t_mlx init error ");
//	win->w = w;
//	win->l = l;
//	win->mid[X] = w / 2;
//	win->mid[Y] = l / 2;
//	win->max_z = 0;
//	win->min_z = 0;
//	win->scale = 2;
////	options(win);
////	if ((win->img = mlx_new_image(win->mp, WIDE, LENGTH)) == NULL)
////		error_notice("mlx_new_image error");
////	if ((win->data = (int *)mlx_get_data_addr(win->img, &bpp, &lsize, &endian)) == NULL)
////		error_notice("mlx_get_data_addr error");
//	win->mp = mlx_init();
//	win->wp = mlx_new_window(win->mp, w, l, "fdf");
////	mlx_hook((&win)->wp, 2, 0L, key_press, (void *)(&win));
//	mlx_key_hook(win->wp, key, (void *)0);
//
//	return (win);
//}