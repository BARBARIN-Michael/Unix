/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:31:01 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/31 11:20:16 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (--n > 0 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

int		ft_multi_strcmp(size_t nbr_elem, char *str, ...)
{
	int		elem_equ;
	int		ret;
	char	*args;
	va_list	ap;

	elem_equ = 1;
	va_start(ap, str);
	while (nbr_elem-- > 0)
	{
		args = (char *)va_arg(ap, char *);
		if ((ret = ft_strcmp(str, args)) == 0)
			return (ret);
		++elem_equ;
	}
	va_end(ap);
	return (1);
}
