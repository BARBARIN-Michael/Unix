/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 21:22:59 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/24 14:47:30 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*hexa_purge(char *s1)
{
	char	*str;
	char	*temp;

	temp = s1;
	while (*s1 == '0' && s1[1] != '\0')
		s1++;
	str = ft_strdup(s1);
	free(temp);
	return (str);
}

char	*handle_hexa(va_list ap, t_opt opt, int x)
{
	char	*str;

	if (x == 0)
	{
		str = ft_special(opt, ap, BASE_16X, &ft_ntoa);
		str = hexa_purge(str);
	}
	else
	{
		str = ft_special(opt, ap, BASE_16X_U, &ft_ntoa);
		str = hexa_purge(str);
	}
	return (str);
}

char	*handle_binaire(va_list ap, t_opt *opt)
{
	char	*str;

	str = ft_special(*opt, ap, BASE_2, &ft_ntoa);
	return (ft_strdup(str));
}
