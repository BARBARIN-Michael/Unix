/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 18:48:10 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/09 13:38:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static char	**get_env(char **envp, char *env, int cmp)
{
	if (envp == NULL || env == NULL || envp[cmp] == NULL)
		return (NULL);
	else if (ft_strncmp(envp[cmp], env, ft_strlen(env)) == 0 &&
			envp[cmp][ft_strlen(env)] == '=')
		return (envp + cmp);
	else
		return (get_env(envp, env, cmp + 1));
}

char		*ft_get_env(char **envp, char *env)
{
	char	**getenv;

	getenv = get_env(envp, env, 0);
	if (getenv == NULL || *getenv == NULL)
		return (NULL);
	return (&(*getenv)[ft_strlen(env) + 1]);
}

