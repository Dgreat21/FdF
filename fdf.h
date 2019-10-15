/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:50:50 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/15 22:29:00 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "libft/libft.h"
# include <math.h>
# define LEN 100
# define PI 3.14159265359
# define WIDE 1000
# define LENGTH 1000

# define AQUA 0x00ffff
# define BLACK 0x000000
# define BLUE 0x0000ff
# define FUCHSIA 0xff00ff
# define GRAY 0x808080
# define GREEN 0x008000
# define LIME 0x00ff00
# define MAROON 0x800000
# define NAVY 0x000080
# define OLIVE 0x808000
# define PURPLE 0x800080
# define RED 0xff0000
# define SILVER 0xc0c0c0
# define TEAL 0x008080
# define WHITE 0xffffff
# define YELLOW 0xffff00

# define R 0xFF0000
# define G 0x00FF00
# define B 0x0000FF

typedef struct		s_glist
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_glist;

typedef struct		s_argb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_argb;

typedef union		u_color
{
	int				mlx;
	t_argb			rgb;
}					t_color;

typedef struct		s_opt
{
	short			rot;//rotation
	short			grad;//gradient
	short			xyz;//show xyz
	unsigned int	scale;//scale
	short			dt_mode;//dot mode
	short			axis;
}					t_opt;

enum				e_O{Y, X};

typedef struct		s_mlx
{
	void			*mp;
	void			*wp;
	int				w;
	int				l;
	int				mid[2];
	t_glist			map;
	unsigned int	dist;
	struct s_opt	opt;
}					t_mlx;

typedef struct		s_line
{
	struct s_glist	d0;
	struct s_glist	d1;
	short			dir;
	float			k;
	int				color;
}					t_line;

t_mlx				window(int w, int l);

void				drawer(t_mlx win, t_line l);

t_line				line(t_glist a, t_glist b, int color);

void				show_xyz(t_mlx win);

void				swap_glist(t_glist *a, t_glist *b);

void				vardot(char *s, t_glist a);

t_glist				set_dot(float x, float y);

void				pixel(t_mlx win, t_glist dot, int color);

void				draw_map( t_mlx win, t_glist **map);

void				ft_foreach(t_mlx win, t_glist **tab, void (*f)(char *, t_glist));

//t_map				g_data;
#endif
