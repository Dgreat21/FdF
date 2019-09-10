/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:31:59 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/02 17:32:52 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vardump(char *str, int a)
{
	ft_putstr(str);
	ft_putstr(":");
	ft_putnbr(a);
	ft_putendl("");
}