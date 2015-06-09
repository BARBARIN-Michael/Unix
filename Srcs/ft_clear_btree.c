/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_btree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:53:12 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 12:02:11 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void		clear_left(t_btree *tree)
{
	t_btree		*tmp;
	t_btree		*tmp2;
	int			i;

	tmp = tree->left;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		i = 0;
		while (tmp->args_tab[i] != NULL)
		{
			ft_strdel(&tmp->args_tab[i]);
			++i;
		}
		free(tmp->args_tab);
		tmp = tmp->left;
		free(tmp2);
	}
}

void			ft_clear_btree(t_btree **tree)
{
	t_btree		*tmp;
	t_btree		*tmp2;
	int			i;

	tmp = *tree;
	if (!tree)
		return ;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		clear_left(tmp);
		i = 0;
		while (tmp->args_tab[i] != NULL)
		{
			ft_strdel(&tmp->args_tab[i]);
			++i;
		}
		free(tmp->args_tab);
		tmp = tmp->right;
		free(tmp2);
	}
}
