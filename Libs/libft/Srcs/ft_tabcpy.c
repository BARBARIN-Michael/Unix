/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 10:29:44 by mbarbari          #+#    #+#             */
/*   Updated: 2015/09/30 15:48:48 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_tabcpy_by_value(char **tab, size_t offset)
{
	char	**cpy;
	int		len;

	len = ft_array_count((void **)tab);
	cpy = (char **)ft_memalloc(sizeof(char *) * (len + 1 + offset));
	while (len > -1)
	{
		cpy[len] = ft_strdup(tab[len]);
	}
	return (cpy);
}

char	**ft_tabcpy_by_ptr(char **tab, size_t offset)
{
	char	**cpy;
	int		len;

	len = ft_array_count((void **)tab);
	cpy = (char **)ft_memalloc(sizeof(char *) * (len + 1 + offset));
	cpy[len + 1] = NULL;
	while (len > -1)
	{
		cpy[len] = tab[len];
		--len;
	}
	return (cpy);
}
