/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnode_btree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 12:01:45 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 12:01:47 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void ft_addnode_btree(t_btree **tree, t_operand op, t_btree *n)
{
	t_btree *tmp;

	if (tree && *tree)
	{
		tmp = *tree;
		if (tmp->right != NULL)
			ft_addnode_btree(&(*tree)->right, op, n);
		else if (op != o_pipe &&
				(op < o_red_dl || op > o_red_e))
			ft_addnode_btree(&(*tree)->right, op, n);
		else
			ft_addnode_btree(&(*tree)->left, op, n);
	}
	else
		*tree = n;
}
