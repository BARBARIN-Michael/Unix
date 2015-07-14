/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 19:26:38 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/13 04:17:28 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(char *src, size_t len)
{
	char	*str;

	if (!src)
	{
		src = (void *)malloc(sizeof(src) * (len + 1));
		if (!src)
			return (NULL);
		return (src);
	}
	else
	{
		str = (char *)malloc(sizeof(src) * (ft_strlen(src) + len));
		if (!str)
			return (NULL);
		else
			str = ft_strcpy(str, src);
		ft_strdel(&src);
	}
	return (str);
}
