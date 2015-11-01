/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:55:02 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/29 18:38:28 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		c_a;
	char	*new;

	c_a = 0;
	if (!(new = ft_strnew(ft_strlen(str) + 1)))
		return (NULL);
	else
	{
		while (str[c_a] != '\0')
		{
			new[c_a] = str[c_a];
			c_a++;
		}
		new[c_a] = '\0';
		return (new);
	}
}

char	*ft_strndup(const char *str, size_t n)
{
	int		c_a;
	char	*new;

	c_a = 0;
	if (!(new = ft_memalloc(sizeof(char) * (n + 1))))
		return (NULL);
	else
	{
		while (str[c_a] != '\0' && n)
		{
			new[c_a] = str[c_a];
			++c_a;
			--n;
		}
		return (new);
	}
}
