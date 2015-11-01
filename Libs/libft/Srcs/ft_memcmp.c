/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:07:09 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/09 22:13:43 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				result;
	unsigned char	*src1;
	unsigned char	*src2;

	result = 0;
	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	while (n > 0 && *src1 == *src2)
	{
		n--;
		src1++;
		src2++;
	}
	if (n == 0)
		return (0);
	else
		return (*src1 - *src2);
	return (result);
}
