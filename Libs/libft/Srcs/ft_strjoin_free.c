/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 10:16:51 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/26 10:54:43 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strjoin_free(char *src, char *join, int mod)
{
	char		*str;

	if (!src || !join)
		return (NULL);
	str = (char *)ft_memalloc(ft_strlen(src) + ft_strlen(join) + 1);
	ft_strcpy(str, src);
	ft_strcat(str, join);
	if (mod == 'l' || mod == 'g')
		free(src);
	else if (mod == 'r' || mod == 'd')
		free(join);
	else if (mod == 'c')
	{
		free(src);
		free(join);
	}
	return (str);
}
