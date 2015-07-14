/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:35:18 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 14:55:27 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}

void	ft_strndel(int n, ...)
{
	va_list ap;

	va_start(ap, n);
	while (n)
	{
		ft_memdel((void **)va_arg(ap, void **));
		n--;
	}
	va_end(ap);
}

void	ft_tabdel(char **tab)
{
	int		cmp;

	cmp = 0;
	while (tab[cmp] != NULL)
	{
		free(tab[cmp]);
		++cmp;
	}
}

void	ft_tabndel(char **tab, size_t n)
{
	while (n)
	{
		free(tab[n]);
		--n;
	}
	free(tab[0]);
	free(tab);
}
