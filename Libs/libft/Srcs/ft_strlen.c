/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:55:15 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/21 19:20:15 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wlen(wchar_t c)
{
	if (c <= 0x7f)
		return (1);
	else if (c <= 0x7ff)
		return (2);
	else if (c <= 0xffff)
		return (3);
	else if (c <= 0x10ffff)
		return (4);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str && *str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

size_t	ft_wstrlen(const wchar_t *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str += ft_wlen(*str);
		str++;
	}
	return (i);
}

size_t	ft_strlen_by_c(const char *str, int c)
{
	int		cmp;
	int		cmpc;

	cmp = 0;
	cmpc = 0;
	while (str[cmp])
	{
		if (str[cmp] == c)
			cmpc++;
		cmp++;
	}
	return (cmpc);
}
