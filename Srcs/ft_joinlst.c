/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:54:10 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 12:02:37 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int	ft_join_string(t_lst_bdin *cpy)
{
	t_lst_bdin *tmp;

	cpy->cde_name = cpy->sauvegarde;
	cpy->sauvegarde = NULL;
	ft_tabaddargs(cpy, cpy);
	if (cpy->next != NULL && cpy->next->operand == o_string)
	{
		tmp = cpy;
		while (tmp->next != NULL && tmp->next->operand == o_string)
		{
			tmp = tmp->next;
			if (ft_tabaddargs(cpy, tmp) < 0)
				return (-1);
		}
	}
	return (0);
}

static int	ft_join_else(t_lst_bdin *cpy)
{
	t_lst_bdin *tmp;

	if (cpy->next != NULL && cpy->next->operand == o_string)
	{
		tmp = cpy->next;
		cpy->cde_name = tmp->sauvegarde;
		tmp->sauvegarde = NULL;
		tmp->operand = o_empty;
		ft_tabaddargs(cpy, cpy);
		while (tmp->next != NULL && tmp->next->operand == o_string)
		{
			tmp = tmp->next;
			if (ft_tabaddargs(cpy, tmp) < 0)
				return (-1);
		}
	}
	else
		return (RN_ERR("Missing argument\n"), -1);
	return (0);
}

static int	ft_sortlst(t_lst_bdin *cpy)
{
	int		ret;

	ret = 0;
	if (cpy->operand >= o_red_dl && cpy->operand <= o_red_e)
	{
		if (ft_join_red(cpy) < 0)
			return (-1);
	}
	else if (cpy->operand > o_undef && cpy->operand <= o_and_d)
		ret = ft_join_else(cpy);
	else if (cpy->operand == o_string)
		if (ft_join_string(cpy) < 0)
			return (-1);
	if (cpy->operand == o_undef || ret != 0)
		return (RN_ERR("operand does not exist"), -1);
	return (0);
}

int			ft_joinlst(t_env *env)
{
	t_lst_bdin		*cpy;

	cpy = env->lst_bdin;
	if (cpy && cpy->next != NULL)
	{
		while (cpy && cpy->next != NULL)
		{
			if (ft_sortlst(cpy) < 0)
				return (-1);
			cpy = cpy->next;
			if (cpy && cpy->next == NULL)
				if (ft_sortlst(cpy) < 0)
					return (-1);
		}
	}
	else if (cpy && cpy->next == NULL)
	{
		if (cpy->operand == o_string && ft_join_string(cpy) < 0)
			return (-1);
		else if (cpy->operand != o_string)
			return (RN_ERR("command invalid\n"), -1);
	}
	return (0);
}
