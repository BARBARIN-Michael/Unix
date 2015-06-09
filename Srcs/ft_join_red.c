/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_red.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:53:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 12:02:30 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int		ft_shift_args(t_lst_bdin *cpy, t_lst_bdin *tmp)
{
	int			flag;

	flag = 0;
	while (tmp->prev != NULL && (tmp->prev->operand < o_multi ||
				tmp->prev->operand > o_and_d) && tmp->prev->operand != o_string)
	{
		flag = 1;
		tmp = tmp->prev;
	}
	if (tmp->prev != NULL && flag)
		tmp = tmp->prev;
	ft_tabaddargs(tmp, cpy);
	while (cpy->next != NULL && cpy->next->operand == o_string)
	{
		cpy = cpy->next;
		if (ft_tabaddargs(tmp, cpy) < 0)
			return (-1);
	}
	return (0);
}

int				ft_join_red(t_lst_bdin *cpy)
{
	t_lst_bdin	*tmp;

	if (cpy->prev == NULL)
		return (RN_ERR("Missing argument before '>'\n"), -1);
	else if (cpy->next != NULL && cpy->next->operand == o_string)
	{
		cpy->cde_name = cpy->next->sauvegarde;
		cpy->next->sauvegarde = NULL;
		cpy->next->operand = o_empty;
		cpy->sauvegarde = NULL;
		if ((ft_tabaddargs(cpy, cpy)) < 0)
			return (-1);
		if (cpy->next->next != NULL && cpy->next->next->operand == o_string)
		{
			tmp = cpy;
			cpy = cpy->next->next;
			if (ft_shift_args(cpy, tmp) < 0)
				return (-1);
		}
		return (0);
	}
	return (RN_ERR("Missing argument after '>'\n"), -1);
}
