/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:50:50 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/05 23:44:01 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "libft/libft.h"
# include <math.h>
# define LEN 100

# define AQUA 0x00ffff
# define BLACK 0x000000
# define BLUE 0x0000ff
# define FUCHSIA 0xff00ff
# define GRAY 0x808080
# define GREEN 0x008000
# define LINE 0x00ff00
# define MAROON 0x800000
# define NAVY 0x000080
# define OLIVE 0x808000
# define PURPLE 0x800080
# define RED 0xff0000
# define SILVER 0xc0c0c0
# define TEAL 0x008080
# define WHITE 0xffffff
# define YELLOW 0xffff00

# define R 0x100000
# define G 0x001000
# define B 0x000010

typedef struct		s_glist
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_glist	*next;
}					t_glist;

typedef struct		s_mlx
{
	void			*mp;
	void			*wp;
}					t_mlx;

typedef struct		s_line
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				r;
	int				g;
	int				b;
}					t_line;

#endif
