/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node_btree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:53:34 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/31 17:53:36 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>
#include <stdlib.h>

t_btree	*ft_create_node_btree(char *cde_name, char **args_tab, t_operand o)
{
	t_btree	*btree;

	btree = NULL;
	btree = (t_btree*)ft_memalloc(sizeof(t_btree));
	if (!btree)
		return (NULL);
	if (btree)
	{
		btree->left = NULL;
		btree->right = NULL;
		btree->operand = o;
		btree->error = 0;
		btree->fd_prev = 0;
		if (cde_name)
			btree->cde_name = cde_name;
		else
			btree->cde_name = NULL;
		if (args_tab)
			btree->args_tab = args_tab;
		else
			btree->args_tab = NULL;
	}
	return (btree);
}
