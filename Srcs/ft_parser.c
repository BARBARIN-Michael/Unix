/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:56:22 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/31 17:56:23 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		ft_parser(char *str, t_env *env)
{
	if (!str)
		return (0);
	if (ft_parsing(str, env) < 0)
	{
		ft_lst_sh_del(&env->lst_bdin);
		return (-1);
	}
	if ((ft_joinlst(env)) < 0)
	{
		ft_lst_sh_del(&env->lst_bdin);
		return (-1);
	}
	if (ft_lstinbtree(env) < 0)
	{
		ft_lst_sh_del(&env->lst_bdin);
		return (-1);
	}
	ft_lst_sh_del(&(env->lst_bdin));
	return (0);
}
