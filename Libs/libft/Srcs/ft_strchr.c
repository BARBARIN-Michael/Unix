/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 13:40:52 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/30 15:03:22 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_nstrchr(const char *s, int c, size_t n)
{
	char *endstr;

	if (!s)
		return (NULL);
	endstr = (char *)s;
	if (n <= 0)
		return ((char *)&s[0]);
	while (endstr && n)
	{
		if (*endstr == c)
		{
			--n;
			if (n <= 0)
				return (endstr);
		}
		++endstr;
	}
	return (NULL);
}

char	*ft_nstrrchr(const char *s, int c, size_t n)
{
	char	*endstr;

	if (!s)
		return (NULL);
	if (n <= 0)
		return ((char *)&s[0]);
	endstr = ft_strchr(s, '\0');
	while (endstr != &s[0])
	{
		if (*endstr == c)
		{
			--n;
			if (n <= 0)
				return (endstr);
		}
		--endstr;
	}
	return ((char *)s);
}
