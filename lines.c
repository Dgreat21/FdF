/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 03:26:25 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/07 06:58:34 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define COLOR WHITE

//void    ft_foreach(int *tab, int length, void (*f)(int))
//{
//	int     i;
//
//	i = 0;
//	while (i < length)
//	{
//		(*f)(tab[i]);
//		i++;
//	}
//}

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

// void	ft_foreach(t_mlx win, t_glist **tab, unsigned int *len,
// 		void (*f)(win, t_glist, int))
// {
// 	int		i;
// 	int		j;

// 	i = -1;
// 	while (++i < len[0])
// 	{
// 		j = -1;
// 		while (++j < len[1])
// 		{
// 			(*f)(tab[i][j]);
// 		}
// 	}
// }

void	ft_foreach_dot(t_mlx win, t_glist **tab, unsigned int *len,
		t_glist (*f)(t_mlx , t_glist))
{
	int		i;
	int		j;

	i = -1;
	while (++i < len[0])
	{
		j = 0;
		while (++j < len[1])
		{
			if (win.opt.dt_mode)
			{
				(j == 1) ? (pixel(win, (*f)(win, tab[i - 1][j - 1]), COLOR)) : ();
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
	ft_foreach(win, map, drw_dt_dim);
}
//void	my_test()
//{
//	mlx_new_image();
//	mlx_put_image_to_window();
//
//}
