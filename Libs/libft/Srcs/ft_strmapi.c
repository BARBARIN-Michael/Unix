/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:32:16 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/23 17:21:49 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		offset;

	if (!s || !f)
		return (NULL);
	offset = 0;
	str = ft_strnew(ft_strlen(s));
	if (!str)
		return (NULL);
	while (*s != '\0')
	{
		*str = f(offset, *s);
		str++;
		s++;
		offset++;
	}
	*str = '\0';
	return (str - offset);
}
