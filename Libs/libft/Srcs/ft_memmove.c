/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:16:35 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/23 17:28:39 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!len || !src || !dst)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (s < d)
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	else
		ft_memcpy(d, s, len);
	return (d);
}
