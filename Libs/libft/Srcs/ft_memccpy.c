/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:53:38 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/09 22:09:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *str_dst;
	char *str_src;

	str_dst = (char *)dst;
	str_src = (char *)src;
	while (n > 0 && *str_src != c)
	{
		n--;
		*str_dst++ = *str_src++;
	}
	if (n > 0)
	{
		*str_dst++ = *str_src++;
		return (str_dst);
	}
	else
		return (NULL);
}
