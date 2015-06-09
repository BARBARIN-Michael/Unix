/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 21:26:53 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/16 19:53:03 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char *ft_strset(char *s1, int pos, int nbr, int car)
{
	char	*str;

	if (!(str = ft_memalloc(ft_strlen(s1) + nbr + 1)))
		return (NULL);
	if (pos > 0)
	{
		str = ft_strncat(str, s1, pos);
		s1 += pos;
	}
	while (nbr)
	{
		str[pos] = car;
		pos++;
		nbr--;
	}
	str = ft_strcat(str, s1);
	return (str);
}
