/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 13:09:26 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/30 23:06:30 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_replace(char *str, char *mod, char *strtoreplace)
{
	char	*endstr;
	char	*st2;

	endstr = ft_memalloc((ft_strlen(str) - 2) + ft_strlen(strtoreplace) + 1);
	if (ft_strcmp(mod, "%s") == 0)
	{
		st2 = ft_strstr(str, mod);
		endstr = ft_strncat(endstr, str, (st2 - str));
		endstr = ft_strcat(endstr, strtoreplace);
		endstr = ft_strcat(endstr, st2 + 2);
	}
	return (endstr);
}
