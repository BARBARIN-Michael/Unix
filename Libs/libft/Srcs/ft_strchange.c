/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 15:11:12 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/28 08:45:56 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_checking.h>

char		*ft_strchange(char *s1, char *mod, char *new)
{
	int		cmp[2];
	char	*save[3];
	int		len;

	ft_bzero(cmp, sizeof(cmp));
	save[0] = s1;
	if (ft_strstr(s1, mod) == NULL)
		return (s1);
	while (ft_strnstr(s1, mod, cmp[0] + 1))
		++cmp[0];
	len = ft_strlen(s1) - (ft_strlen(mod) * cmp[0]) + (ft_strlen(new) * cmp[0]);
	CHECK_MEM((save[2] = (char *)ft_memalloc(sizeof(char) * len)));
	while (1)
	{
		if ((save[1] = ft_strnstr(s1, mod, cmp[1]++)))
		{
			ft_strncat(save[2], save[0], save[1] - save[0]);
			ft_strncat(save[2], new, ft_strlen(new));
			save[0] = save[1] + ft_strlen(mod);
			continue ;
		}
		ft_strncat(save[2], save[0], ft_strlen(save[0]));
		break ;
	}
	return (save[2]);
}
