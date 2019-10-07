/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 03:26:25 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/07 09:37:28 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define COLOR WHITE

t_glist	drw_dt_dim(t_mlx win, t_glist dot)//to dimetry
{
	float	x;
	float	y;

	x = win.mid[X] + dot.x - dot.y * cos(PI / 4);
	y = win.mid[Y] - dot.z + dot.y * cos(PI / 4);
	return(set_dot(x, y));
}

t_glist	drw_dt_iso(t_mlx win, t_glist dot)//to isometry
{
	float	x;
	float	y;

	x = win.mid[X] + (dot.x - dot.y) * cos(PI / 6);
	y = win.mid[Y] - dot.z + (dot.x + dot.y) * cos(PI / 3);
	return(set_dot(x, y));
}

 void	ft_foreach(t_mlx win, t_glist **tab, void (*f)(char *, t_glist))
 {
 	int		i;
 	int		j;

 	i = -1;
 	while (++i < win.map.y)
 	{
 		j = -1;
 		while (++j < win.map.x)
 		{
 			(*f)(ft_itoa(i * win.map.x + j), tab[i][j]);
 		}
 	}
 }

void	ft_foreach_dot(t_mlx win, t_glist **tab, t_glist (*f)(t_mlx , t_glist))// todo segmentation fault
{
	int		i;
	int		j;

	i = -1;
	while (++i < win.map.y)
	{
		j = -1;
		while (++j < win.map.x)
		{
			vardump("j", j);
			if (win.opt.dt_mode)
			{
//				pixel(win, tab[i][j], COLOR);
				(j == 1) ? (pixel(win, (*f)(win, tab[i - 1][j - 1]), COLOR)) : (0);
				pixel(win, (*f)(win, tab[i][j]), COLOR);
			}
			else
			{
				drawer(win, line((*f)(win, tab[i][j]), (*f)(win, tab[i - 1][j - 1]), COLOR));
			}
		}

	}
}



void	draw_map( t_mlx win, t_glist **map)
{
//	vardot("test1", map[0][0]);
//	ft_foreach(win, map, vardot);
	ft_foreach_dot(win, map, drw_dt_iso);
}

//void	my_test()
//{
//	mlx_new_image();
//	mlx_put_image_to_window();
//
//}
