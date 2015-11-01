/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 03:08:03 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/09 22:23:51 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char *str;

	str = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			str = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	else
		return (str);
}
