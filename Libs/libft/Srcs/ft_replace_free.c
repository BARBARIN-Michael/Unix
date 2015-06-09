/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:25:51 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 18:47:11 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	del_replace(char *s1, char *mod, char *s2, int mod_free)
{
	if (mod_free == 'l' || mod_free == 'g')
		free(s1);
	else if (mod_free == 'r' || mod_free == 'd')
		free(s2);
	else if (mod_free == 'c')
	{
		free(s1);
		free(s2);
	}
	else if (mod_free == 'a')
	{
		free(mod);
		free(s1);
		free(s2);
	}
}

char		*ft_replace_free(char *s1, char *mod, char *s2, int mod_free)
{
	char	*rslt;
	char	*st2;
	int		lenmod;

	lenmod = ft_strlen(mod);
	rslt = ft_memalloc(ft_strlen(s1) - lenmod + ft_strlen(s2) + 2);
	if (!(st2 = ft_strstr(s1, mod)))
		return (NULL);
	rslt = ft_strncat(rslt, s1, (st2 - s1));
	rslt = ft_strcat(rslt, s2);
	rslt = ft_strcat(rslt, st2 + lenmod);
	del_replace(s1, mod, s2, mod_free);
	return (rslt);
}
