/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:13:28 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/13 03:58:16 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	ft_putchar('0' + (nbr % 10));
}
