/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:02:24 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 18:45:15 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static int		is_sign(intmax_t nbr)
{
	if (nbr < 0)
		return (1);
	else
		return (0);
}

static int		nbr_digit(intmax_t nbr)
{
	int		cmp_digit;

	cmp_digit = 0;
	if (nbr < 0)
	{
		cmp_digit++;
		nbr = -nbr;
	}
	if (nbr == 0)
		cmp_digit++;
	while ((nbr) != 0)
	{
		cmp_digit++;
		nbr /= 10;
	}
	return (cmp_digit);
}

char			*ft_itoa(intmax_t nbr)
{
	char	*str;
	int		cmp;
	int		sign;

	if (nbr == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (nbr == 0)
		return ("0");
	cmp = nbr_digit(nbr);
	str = ft_strnew(cmp);
	sign = 0;
	sign = is_sign(nbr);
	if (sign == 1)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	str[cmp] = '\0';
	while (nbr)
	{
		str[cmp - 1] = '0' + (nbr % 10);
		nbr /= 10;
		cmp--;
	}
	return (str);
}

char			*ft_utoa(uintmax_t nbr)
{
	char	*str;
	int		cmp;

	if (nbr == ULONG_MAX)
		return (ft_strdup("18446744073709551615"));
	if (nbr == 0)
		return ("0");
	cmp = nbr_digit(nbr);
	str = ft_strnew(cmp);
	str[cmp] = '\0';
	while (nbr)
	{
		str[cmp - 1] = '0' + (nbr % 10);
		nbr /= 10;
		cmp--;
	}
	return (str);
}
