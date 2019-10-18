/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 08:49:56 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/18 04:19:29 by dgreat           ###   ########.fr       */
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

t_glist	set_xyz(float x, float y, float z)
{
	t_glist	dot;

	dot.x = x;
	dot.y = y;
	dot.z = z;
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

t_line	line(t_glist a, t_glist b)
{
	t_line	l;

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
