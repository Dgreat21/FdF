/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:14:55 by dgreat            #+#    #+#             */
/*   Updated: 2019/04/17 06:17:43 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		num(char c)
{
	int		n;
	char	*sys;

	n = 0;
	sys = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
	while (sys[n])
	{
		if (sys[n] == c)
			return (n);
		n++;
	}
	return (0);
}

static int		sys(char c, int base)
{
	if (num(c) < base)
		return (1);
	else
		return (0);
}

int				ft_atoi_base(const char *s, int base)
{
	long int	nb;
	int			i;
	int			f;
	long int	pnb;

	i = 0;
	pnb = 0;
	f = 0;
	nb = 0;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if ((s[i] > 47 && s[i] < 58) || (s[i] > 64 && s[i] < 91) || (s[i] == '+'))
		f++;
	else if (s[i] == '-')
		f--;
	((s[i] == '+') || (s[i] == '-')) ? (i++) : (0);
	while (sys(s[i], base))
	{
		pnb = nb;
		nb = nb * base + num(s[i]);
		i++;
		if (pnb != nb / base)
			return ((f > 0) ? -1 : 0);
	}
	return (nb * f);
}
