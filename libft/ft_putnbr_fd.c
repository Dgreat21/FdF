/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:17:09 by dgreat            #+#    #+#             */
/*   Updated: 2019/08/22 18:22:19 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int nb, int fd)
{
	int		len;
	int		f;
	long	n;

	n = (long)nb;
	f = (n >= 0) ? (0) : (1);
	n = (n >= 0) ? n : -n;
	len = ft_log(n, 10);
	if (f == 1)
		ft_putchar_fd('-', fd);
	while (len)
	{
		f = ft_pow_uint(10, len - 1);
		ft_putchar_fd(n / f + '0', fd);
		len--;
		n %= f;
	}
}

void		ft_putnbr_base(unsigned int nb, size_t base, short flag)//flag 1 - cap
{
	int		len;
	int		f;
	long	n;
	int		res;

	n = (long)nb;
	//f = (n >= 0) ? (0) : (1);
	//n = (n >= 0) ? n : -n;
	len = ft_log(n, base);
	//if (f == 1)
	//	ft_putchar_fd('-', fd);
	while (len)
	{
		f = ft_pow_uint(base, len - 1);
		res = n/f;
		if (base > 10 && res >= 10)
			ft_putchar((flag) ? (res + 55) : (res + 87));
		len--;
		n %= f;
	}
}