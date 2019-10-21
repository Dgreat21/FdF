/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:35:58 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/21 06:13:45 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

//void	show_xyz(t_mlx win)
//{
//	int		x0;
//	int		y0;
//	t_line	x;
//	t_line	y;
//	t_line	z;
//
//	x0 = win.l / 2;
//	y0 = win.w / 2;
//	x = line(set_dot(x0, y0), set_dot(win.l, y0), WHITE);
//	y = line(set_dot(x0, y0), set_dot(x0, 0), BLUE);
//	z = line(set_dot(x0, y0), set_dot(y0, x0 - y0), GREEN);
//	drawer(win, x);
//	drawer(win, y);
//	drawer(win, z);
//}

int		key(int key)
{
	if (key == kVK_Escape)
		exit(0);
	return (0);
}

int		key_press(int key, void *param)
{
	t_mlx	*win;

	win = (t_mlx *)(param);
	if (key == kVK_Escape)
		exit(0);
	if (key == kVK_ANSI_KeypadPlus)
		win->scale++;
	if (key == kVK_ANSI_KeypadPlus)
		win->scale--;
	if (key == kVK_ANSI_G)
	{
		win->opt.grad = 1;
		ft_putendl("GGGGGG");
	}
	return (0);
}

//void		xyz(t_mlx win, t_glist dot, char *str, t_glist *cur_dot)//todo дописать многофункциольную фунцию изменения координат
//{
//	const int	i = dot.y;
//	const int	j = dot.x;
//	const int	y = i * win.scale;
//	const int	x = j * win.scale;
//
//	if (!((int)win.map.x % 2))
//		(*cur_dot).x = ((float)(j - win.map.x / 2)) * win.scale;
//	else
//		(*cur_dot).x = ((float)(j) - (float)(win.map.x / 2)) * win.scale;
//	if (!((int)win.map.y % 2))
//		(*cur_dot).y = ((float)(i - win.map.y / 2)) * win.scale;
//	else
//		(*cur_dot).y = ((float)(i) - (float)(win.map.y / 2)) * win.scale;
//	(*cur_dot).z = ft_atoi(str) * (win.scale / 2);
//	(*cur_dot).hue.mlx = 0x0;
//}

void		xyz(t_mlx win, t_glist dot, char *str, t_glist *cur_dot)
{
	const int	i = dot.y;
	const int	j = dot.x;
	const int	y = i * win.scale;
	const int	x = j * win.scale;

	if (!((int)win.map.x % 2))
		(*cur_dot).x = ((float)(j - win.map.x / 2)) * win.scale;
	else
		(*cur_dot).x = ((float)(j) - (float)(win.map.x / 2)) * win.scale;
	if (!((int)win.map.y % 2))
		(*cur_dot).y = ((float)(i - win.map.y / 2)) * win.scale;
	else
		(*cur_dot).y = ((float)(i) - (float)(win.map.y / 2)) * win.scale;
	(*cur_dot).z = ft_atoi(str) * (win.scale / 2);
	//(*cur_dot).z = brightness()
	//	if ((*cur_dot).z == 10)
}

t_mlx	window_old(int w, int l)
{
	t_mlx	win;

	win.w = w;
	win.l = l;
	win.mid[X] = w / 2;
	win.mid[Y] = l / 2;
	win.max_z = 0;
	win.min_z = 0;
	win.scale = 2;
	win.opt.hue.mlx = LIME;
	win.mp = mlx_init();
	win.wp = mlx_new_window(win.mp, w, l, "fdf");
	mlx_hook(win.wp, 2, 0L, key_press, (void *)&win);
//	mlx_key_hook(win.wp, key, (void *)0);

	return (win);
}

t_mlx	window(int w, int l)
{
	t_mlx	win;

	win.w = w;
	win.l = l;
	win.mid[X] = w / 2;
	win.mid[Y] = l / 2;
	win.max_z = 0;
	win.min_z = 0;
	win.scale = 2;
	win.opt.hue.mlx = LIME;
//	win.list = map;
	win.mp = mlx_init();
	win.wp = mlx_new_window(win.mp, w, l, "fdf");
//	mlx_hook((&win)->wp, 2, 0L, key_press, (void *)(&win));
	mlx_key_hook(win.wp, key, (void *)0);

	return (win);
}