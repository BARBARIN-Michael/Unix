/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:24:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/13 03:59:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putcolor(char *color)
{
	if (ft_strcmp(color, "red") == 0 || ft_strcmp(color, "RED") == 0)
		return (31);
	else if (ft_strcmp(color, "green") == 0 || ft_strcmp(color, "GREEN") == 0)
		return (32);
	else if (ft_strcmp(color, "brown") == 0 || ft_strcmp(color, "BROWN") == 0)
		return (33);
	else if (ft_strcmp(color, "blue") == 0 || ft_strcmp(color, "BLUE") == 0)
		return (34);
	else if (ft_strcmp(color, "magenta") == 0
				|| ft_strcmp(color, "MAGENTA") == 0)
		return (35);
	else if (ft_strcmp(color, "cyan") == 0 || ft_strcmp(color, "CYAN") == 0)
		return (36);
	else
		return (0);
}

void		ft_putstr_c(char const *s, char *color)
{
	char *palet_color;

	palet_color = ft_strjoin("\033[%sm", s);
	palet_color = ft_replace(palet_color, "%s", ft_itoa(putcolor(color)));
	ft_putstr(palet_color);
	ft_putstr(C_NONE);
	ft_strdel(&palet_color);
}
