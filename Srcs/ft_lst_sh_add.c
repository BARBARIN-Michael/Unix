/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sh_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:54:20 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/31 17:54:21 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
** Description
** Ajoute l'element new en tete de la liste.
** Param. #1
** L'adresse d'un pointeur sur le premier maillon d'une liste.
** Param. #2
** Le maillon a ajouter en tete de cette liste.
*/

void ft_lst_sh_add(t_lst_bdin **alst, t_lst_bdin *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst->prev = new;
		*alst = new;
	}
}
