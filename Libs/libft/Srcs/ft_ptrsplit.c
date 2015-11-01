/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 00:55:58 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/01 23:45:52 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		**ft_ptrsplit(char *str, int c)
{
	char	**ptr;
	char	*inc;
	int		cmp;
	int		nbr_ptr;

	inc = str;
	ptr = NULL;
	cmp = 0;
	nbr_ptr = ft_strlen_by_c(str, c);
	ptr = ft_memalloc(sizeof(char *) * (nbr_ptr + 2));
	ptr[cmp] = str;
	while (++cmp <= nbr_ptr)
	{
		inc = ft_strchr(++inc, c);
		if (*(inc + 1) != '\0')
			ptr[cmp] = (inc + 1);
		*inc = '\0';
	}
	return (ptr);
}
