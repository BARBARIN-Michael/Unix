/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:54:13 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/16 19:08:25 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str_dst;
	const unsigned char	*str_src;

	str_dst = dst;
	str_src = src;
	while (n--)
		*str_dst++ = *str_src++;
	return (dst);
}

void	*ft_multi_memcpy(void *dst, int nbr_elem, ...)
{
	va_list		ap;
	int			mem_size;
	char		*str;

	va_start(ap, nbr_elem);
	while (nbr_elem--)
	{
		mem_size = (int)va_arg(ap, int);
		str = (char *)va_arg(ap, char *);
		ft_memcpy(dst, (const void *)str, mem_size);
	}
	return (dst);
}
