/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisuporlow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 10:37:56 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/24 12:00:29 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strisupper(char *str)
{
	int		cmp;
	int		isalpha;

	cmp = 0;
	isalpha = 0;
	while (str[cmp] != '\0')
	{
		if (ft_isalpha(str[cmp]) && str[cmp] != ft_toupper(str[cmp]))
			return (1);
		if (ft_isalpha(str[cmp]))
			isalpha = 1;
		cmp++;
	}
	if (isalpha != 1)
		return (1);
	return (0);
}

int		ft_strislower(char *str)
{
	int		cmp;
	int		isalpha;

	cmp = 0;
	isalpha = 0;
	while (str[cmp] != '\0')
	{
		if (ft_isalpha(str[cmp]) && str[cmp] != ft_tolower(str[cmp]))
			return (1);
		if (ft_isalpha(str[cmp]))
			isalpha = 1;
		cmp++;
	}
	if (isalpha != 1)
		return (1);
	return (0);
}

int		ft_nstrisupper(char *str, size_t n)
{
	int		cmp;
	int		isalpha;

	cmp = 0;
	isalpha = 0;
	while (str[cmp] != '\0' && n-- > 0)
	{
		if (ft_isalpha(str[cmp]) && str[cmp] != ft_toupper(str[cmp]))
			return (1);
		if (ft_isalpha(str[cmp]))
			isalpha = 1;
		cmp++;
	}
	if (isalpha != 1)
		return (1);
	return (0);
}

int		ft_nstrisnlower(char *str, size_t n)
{
	int		cmp;
	int		isalpha;

	cmp = 0;
	isalpha = 0;
	while (str[cmp] != '\0' || n-- > 0)
	{
		if (ft_isalpha(str[cmp]) && str[cmp] != ft_tolower(str[cmp]))
			return (1);
		if (ft_isalpha(str[cmp]))
			isalpha = 1;
		cmp++;
	}
	if (isalpha != 1)
		return (1);
	return (0);
}
