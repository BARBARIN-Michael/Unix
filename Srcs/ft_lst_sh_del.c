/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sh_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:54:39 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 12:03:08 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void ft_lst_sh_del(t_lst_bdin **first)
{
	t_lst_bdin	*ptr;

	if (first && *first)
	{
		ptr = *first;
		if (ptr->next != NULL)
			ft_lst_sh_del(&(ptr->next));
		free((void *)ptr);
		*first = NULL;
	}
}
