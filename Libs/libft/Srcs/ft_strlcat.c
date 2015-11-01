/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:28:30 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/23 17:21:49 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	len;
	size_t	dst_len;

	d = (char *)ft_memchr(dst, '\0', size);
	s = (char *)src;
	dst_len = ft_strlen(dst);
	len = dst_len + ft_strlen(s);
	if (!d)
		return (size + ft_strlen(src));
	while (dst_len++ < size - 1 && *s)
		*d++ = *s++;
	*d = '\0';
	return (len);
}
