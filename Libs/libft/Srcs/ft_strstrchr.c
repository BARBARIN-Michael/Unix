/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadiffe <agadiffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:37:10 by agadiffe          #+#    #+#             */
/*   Updated: 2015/05/23 15:48:35 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strstrchr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	i2;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		i2 = 0;
		while (s2[i2])
		{
			if (s1[i] == s2[i2] && ft_strstr(&s1[i], s2))
				return ((char *)&s1[i]);
			++i2;
		}
		++i;
	}
	return (NULL);
}

char	*ft_nstrstrchr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	i2;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] && n)
	{
		i2 = 0;
		while (s2[i2])
		{
			if (s1[i] == s2[i2] && ft_strstr(&s1[i], s2))
			{
				--n;
				if (n == 0)
					return ((char *)&s1[i]);
			}
			++i2;
		}
		++i;
	}
	return (NULL);
}
