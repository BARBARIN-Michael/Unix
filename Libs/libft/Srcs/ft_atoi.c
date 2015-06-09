/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:35:43 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/29 08:16:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		is_space(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

int				ft_atoi(const char *str)
{
	int		sign;
	int		rslt;

	sign = 0;
	rslt = 0;
	while (is_space((int)*str))
		str++;
	if (*str == '-')
	{
		sign = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && ft_isdigit(*str))
		rslt = rslt * 10 + (*str++ - '0');
	if (sign)
		return (-rslt);
	else
		return (rslt);
}
