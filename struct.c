/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 08:49:56 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/02 08:49:56 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_glist	set_dot(float x, float y)
{
	t_glist	dot;

	dot.x = x;
	dot.y = y;
	return (dot);
}

void	vardot(char *s, t_glist a)
{
	endl();
	ft_putstr(s);
	ft_putchar('(');
	ft_putnbr(a.x);
	ft_putchar(';');
	ft_putnbr(a.y);
	ft_putchar(')');
	endl();
}

void	swap_glist(t_glist *a, t_glist *b)
{
	ft_fswap(&(a->x), &(b->x));
	ft_fswap(&(a->y), &(b->y));
}

t_line	line(t_glist a, t_glist b, int color)
{
	t_line	l;

	l.color = color;
	l.dir = 1;
	l.d0 = a;
	l.d1 = b;
	if (fabsf(l.d1.y - l.d0.y) > fabsf(l.d1.x - l.d0.x))
	{
		(a.y > b.y) ? (swap_glist(&l.d0, &l.d1)) : (0);
		l.k = (l.d1.x - l.d0.x) / (l.d1.y - l.d0.y);
		l.dir--;
	}
	else
	{
		l.k = (l.d1.y - l.d0.y) / (l.d1.x - l.d0.x);
		(a.x > b.x) ? (swap_glist(&l.d0, &l.d1)) : (0);
	}
	return (l);
}