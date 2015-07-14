/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 14:37:26 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 18:51:10 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*insert_wtoa(int cmp, wint_t c)
{
	char		*dst;

	dst = ft_memalloc(cmp + 1);
	if (c <= 0x7FF)
	{
		dst[0] = ((c >> 6) + 0xC0);
		dst[1] = ((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		dst[0] = ((c >> 12) + 0xE0);
		dst[1] = (((c >> 6) & 0x3F) + 0x80);
		dst[2] = ((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		dst[0] = ((c >> 18) + 0xF0);
		dst[1] = (((c >> 12) & 0x3F) + 0x80);
		dst[2] = (((c >> 6) & 0x3F) + 0x80);
		dst[3] = ((c & 0x3F) + 0x80);
	}
	return (dst);
}

char		*ft_wtoa(wint_t c)
{
	char	*dst;
	char	*str;

	str = (char*)&c;
	dst = ft_strnew(0);
	if (c <= 0x7f)
		return (dst = ft_strjoin(dst, str));
	else if (c <= 0x7ff)
		return (insert_wtoa(2, c));
	else if (c <= 0xffff)
		return (insert_wtoa(3, c));
	else if (c <= 0x10ffff)
		return (insert_wtoa(4, c));
	else
		return (NULL);
}
