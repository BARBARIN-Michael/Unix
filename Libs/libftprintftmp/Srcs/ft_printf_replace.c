/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 15:43:14 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/05 13:05:14 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_replace(t_replace rep, t_var *v)
{
	char	*ori;
	char	*str;
	size_t	i;
	int		a;

	i = -1;
	a = -1;
	ori = rep.s1;
	str = ft_memalloc(rep.ns1 + rep.ns2 + 1);
	while (rep.jump)
	{
		ori = ft_strchr(ori, '%') + 1;
		rep.jump--;
	}
	if (!(ori = ft_strstr(ori, rep.mod)))
		return (ft_strdup(rep.s1));
	str = ft_strncat(str, rep.s1, ori - rep.s1);
	while (++i < rep.ns2)
		str[(ori - rep.s1) + i] = rep.s2[i];
	v->s1 = &str[(ori - rep.s1) + 1];
	if (rep.ns1 > 1)
		while (ori[ft_strlen(rep.mod) + ++a] != '\0')
			str[((ori - rep.s1) + i + a)] = ori[ft_strlen(rep.mod) + a];
	v->init->strlen = a > 0 ? ((ori - rep.s1) + i + a) : ((ori - rep.s1) + i);
	return (str);
}
