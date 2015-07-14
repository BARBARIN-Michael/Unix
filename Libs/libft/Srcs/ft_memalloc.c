/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:07:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/08 21:22:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	if (tmp == NULL)
		return (NULL);
	else
	{
		ft_bzero(tmp, size);
		return (tmp);
	}
}
