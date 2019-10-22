/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:50:50 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/22 22:45:56 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "libft/libft.h"
# include <math.h>
# define LEN 100
# define PI 3.14159265359
# define WIDE 2600
# define LENGTH 1440

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

enum 				e_colors
{
	black = 0x000000,
	navy = 0x000080,
	blue = 0x0000ff,
	green = 0x008000,
	teal = 0x008080,
	lime = 0x00ff00,
	aqua = 0x00ffff,
	maroon = 0x800000,
	purple = 0x800080,
	olive = 0x808000,
	gray = 0x808080,
	silver = 0xc0c0c0,
	red = 0xff0000,
	fuchsia = 0xff00ff,
	yellow = 0xffff00,
	white = 0xffffff,
};

typedef char*		t_string;

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

typedef struct		s_glist
{
	float			x;
	float			y;
	float			z;
	t_color			hue;
}					t_glist;

typedef struct		s_opt
{
	short			rot;//rotation
	short			grad;//gradient
	short			grad3;//gradient
	short			xyz;//show xyz
	short			dt_mode;//dot mode
	short			axis;
	t_color			hue;
}					t_opt;

enum				e_o{Y, X};

typedef struct		s_mlx
{
	void			*mp;
	void			*wp;
	int				w;
	int				l;
	int				mid[2];
	t_glist			map;
	unsigned int	scale;
	struct s_opt	opt;
	int				max_z;
	int				min_z;
	t_color			cent;
	t_color			low;
	t_color			high;
	int				bpp;
	int				lsize;
	int				endian;
	char			*data;
	void			*img;
}					t_mlx;

typedef struct		s_line
{
	t_glist			d0;
	t_glist			d1;
	short			dir;
	float			k;
	t_color			hue;
}					t_line;

t_mlx				window(int w, int l);

float				perc(float start, float end, float cur);

int					grad(float k, t_line l, float x);

int					brightness(t_color hue, float k);



void				brez(t_mlx *win, t_line l);

void				drawer(t_mlx *win, t_line l);

//void				drawer_grad(t_mlx win, t_line l);
void				drawer_grad(t_mlx *win, t_line l);

void				dot_md(t_mlx *win, t_line l);

t_line				line(t_glist a, t_glist b);

void				swap_glist(t_glist *a, t_glist *b);

t_glist				set_dot_c(float x, float y, int hue);

void				vardot(char *s, t_glist a);

void				vard(char *s, t_glist a);

t_glist				set_dot(float x, float y);

t_glist				set_xyz(float x, float y, char *z_color, int color);

void				pixel(t_mlx win, t_glist dot, int color);

void				draw_map(t_mlx *win, t_glist **map);

void				ft_foreach(t_mlx win, t_glist **tab,
		void (*f)(char *, t_glist));

t_glist				drw_dt_iso(t_mlx win, t_glist dot);

t_glist				drw_dt_dim(t_mlx win, t_glist dot);

//t_map				g_data;
#endif
