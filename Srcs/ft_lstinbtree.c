/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinbtree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:55:56 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/31 17:55:58 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int	ft_insertinbtree(t_env *env, t_lst_bdin *cpy)
{
	t_btree *tmp;

	tmp = ft_create_node_btree(cpy->cde_name, cpy->args_tab, cpy->operand);
	if (tmp != NULL)
	{
		ft_addnode_btree(&(env)->bfirst, tmp->operand, tmp);
		cpy->cde_name = NULL;
		cpy->args_tab = NULL;
		cpy->operand = o_empty;
	}
	else
		return (RN_ERR("ft_create_node_btree failed in ft_lstinbtree.c\n"), -1);
	return (0);
}

int			ft_lstinbtree(t_env *env)
{
	t_lst_bdin *cpy;

	cpy = env->lst_bdin;
	env->bfirst = NULL;
	if (cpy && cpy->next != NULL)
	{
		while (cpy && cpy->next != NULL)
		{
			if (cpy->operand != o_empty)
				if (ft_insertinbtree(env, cpy) < 0)
					return (-1);
			cpy = cpy->next;
			if (cpy && cpy->next == NULL && cpy->operand != o_empty)
				if (ft_insertinbtree(env, cpy) < 0)
					return (-1);
		}
	}
	else if (cpy && cpy->next == NULL)
	{
		if (cpy->operand != o_empty)
			if (ft_insertinbtree(env, cpy) < 0)
				return (-1);
	}
	return (0);
}
