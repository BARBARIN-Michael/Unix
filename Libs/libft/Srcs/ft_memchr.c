/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:53:55 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/09 22:13:09 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char*)src;
	while (*str != (unsigned char)c && len > 0)
	{
		len--;
		str++;
	}
	if (len == 0)
		return (NULL);
	else
		return (str);
}
