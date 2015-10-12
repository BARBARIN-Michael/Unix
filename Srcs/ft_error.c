/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 11:41:10 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/12 11:41:34 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int	test_exit(int status)
{
	int		ret;

	ret = 0;
	if (WIFEXITED(status))
		ret = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		ret = WTERMSIG(status);
	else if (WIFSTOPPED(status))
		ret = status;
	return (ret);
}

void	ft_printerr(t_env *env, t_btree *tree)
{
	if (ft_strcmp(tree->cde_name, "$1") == 0)
		env->error == 0 ?
			ft_printf("%d --> %sLe programme c'est execute correctement!%s\n",
			env->error, C_GREEN, C_NONE) :
			ft_printf("%d --> %sLe programme c'est execute avec erreur!%s\n",
			env->error, C_RED, C_NONE);
}

