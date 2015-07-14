/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sh_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:55:11 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/31 17:55:17 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>
#include <stdlib.h>

t_lst_bdin *ft_lst_sh_new(t_operand oper, char *str)
{
	t_lst_bdin	*elem;

	elem = (t_lst_bdin *)malloc(sizeof(t_lst_bdin));
	if (!elem)
		return (NULL);
	if (elem)
	{
		ft_bzero((void *)elem, sizeof(t_lst_bdin));
		if (str != NULL)
			elem->sauvegarde = ft_strdup(str);
		else
			elem->sauvegarde = NULL;
		elem->cde_name = NULL;
		elem->operand = oper;
		elem->args_tab = NULL;
		elem->next = NULL;
		elem->prev = NULL;
	}
	return (elem);
}
