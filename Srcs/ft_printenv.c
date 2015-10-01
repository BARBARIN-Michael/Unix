/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 14:14:12 by mbarbari          #+#    #+#             */
/*   Updated: 2015/09/30 16:08:42 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_sh.h>

void		ft_print_env(char **envp)
{
	int		cmp;
	int		len;

	cmp = 0;
	while (envp[cmp] != NULL)
	{
		len = ft_strchr(envp[cmp], '=') - envp[cmp];
		if (len && (ft_nstrisupper(envp[cmp], len)) == 0)
		{
			ft_printf("%s%.*s%s ", BLUE, len, envp[cmp], C_NONE);
			ft_printf("%s%s%s\n", C_BROWN, envp[cmp] + len + 1, C_NONE);
		}
		++cmp;
	}
}
