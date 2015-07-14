/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sh_addend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:54:32 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/31 17:54:33 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

/*
** Ajoute l'element new_elem en fin de liste.
*/

void ft_lst_sh_addend(t_lst_bdin **alst, t_lst_bdin *new_elem)
{
	t_lst_bdin	*cpy;

	if (!alst && !*alst)
	{
		ft_putendl("error ft_lstdaddend()");
		return ;
	}
	if (*alst == NULL)
		*alst = new_elem;
	else if (alst && new_elem)
	{
		cpy = *alst;
		while (cpy->next != NULL)
			cpy = cpy->next;
		cpy->next = new_elem;
		new_elem->prev = cpy;
	}
}
