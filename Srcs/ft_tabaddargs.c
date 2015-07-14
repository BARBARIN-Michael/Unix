/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabaddargs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:56:57 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 12:06:02 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void	ft_tab_del(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		--j;
	}
	free(tab);
}

static int	ft_dst_fill(t_lst_bdin *dst, t_lst_bdin *src, char **tmp)
{
	int		i;
	int		j;
	char	**prev;

	i = 0;
	prev = dst->args_tab;
	while (dst->args_tab[i] != NULL)
		i++;
	tmp = (char **)ft_memalloc(sizeof(char *) * (i + 2));
	j = i;
	if (!tmp)
		return (RN_ERR("malloc() failed in ft_tabaddargs\n"), -1);
	tmp[i] = src->sauvegarde;
	src->sauvegarde = NULL;
	src->operand = o_empty;
	while (--i >= 0)
	{
		tmp[i] = dst->args_tab[i];
		dst->args_tab[i] = NULL;
	}
	dst->args_tab = tmp;
	ft_tab_del(prev, j);
	return (0);
}

static int	ft_dst_empty_cmd(t_lst_bdin *dst, t_lst_bdin *src, char **tmp)
{
	tmp = (char **)ft_memalloc(sizeof(char *) * 2);
	if (!tmp)
		return (RN_ERR("malloc() failed in ft_tabaddargs\n"), -1);
	tmp[0] = src->cde_name;
	dst->args_tab = tmp;
	return (0);
}

int			ft_tabaddargs(t_lst_bdin *dst, t_lst_bdin *src)
{
	char	**tmp;

	tmp = NULL;
	if (dst->args_tab != NULL)
		return (ft_dst_fill(dst, src, tmp));
	else
		return (ft_dst_empty_cmd(dst, src, tmp));
}
