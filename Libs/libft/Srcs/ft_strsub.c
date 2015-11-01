/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:43:53 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 18:50:32 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char	*str;

	str = malloc(len + 1);
	if (!s1 || !str)
		return (NULL);
	ft_strncpy(str, s1 + start, len);
	str[len] = '\0';
	return (str);
}

char	*ft_wstrsub(char const *s1, unsigned int start, size_t len)
{
	char	*str;
	char	*save;
	int		i;

	i = 0;
	str = ft_memalloc((len * 4) + 1);
	if (!s1 || !str)
		return (NULL);
	save = ft_strdup(s1);
	while (start)
	{
		i += ft_wlen(*(save++));
		start--;
	}
	while (len)
	{
		if (len <= (size_t)ft_wlen(*(wchar_t*)save))
			break ;
		str = ft_strncat(str, save, ft_wlen(*(wchar_t*)save));
		len -= ft_wlen(*(wchar_t*)save);
		save += ft_wlen(*(wchar_t*)save);
	}
	return (str);
}
