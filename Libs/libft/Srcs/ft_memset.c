/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:54:30 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/09 22:15:52 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr_to_str;

	ptr_to_str = (unsigned char*)b;
	while (len--)
		*ptr_to_str++ = c;
	return (b);
}
