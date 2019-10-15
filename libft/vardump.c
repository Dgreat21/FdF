/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:31:59 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/15 21:18:24 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*vardump(char *str, int a)
{
//	ft_putstr(str);
//	ft_putstr(":");
//	ft_putnbr(a);
//	endl();
	str = ft_strjoin(str, ":");
	str = ft_strjoin(str, ft_itoa(a));
	str = ft_strjoin(str, "\n");
	return (str);
}
