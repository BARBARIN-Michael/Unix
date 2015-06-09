/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 18:48:10 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 16:05:07 by mbarbari         ###   ########.fr       */
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

void		ft_set_env(char ***envp, char *env, char *new)
{
	char	**getenv;
	char	**new_env;
	int		len;

	getenv = NULL;
	if (!env || !new)
	{
		N_ERR("Setenv need two arguement!\n");
		return ;
	}
	getenv = get_env(*envp, env, 0);
	if (!(getenv))
	{
		len = ft_array_count((void **)*envp);
		new_env = ft_tabcpy_by_ptr(*envp, 2);
		new_env[len] = ft_multi_strjoin(3, env, "=", new);
		new_env[len + 1] = NULL;
		free(*envp);
		*envp = new_env;
		return ;
	}
	free(*getenv);
	*getenv = ft_multi_strjoin(3, env, "=", new);
}

int			ft_unset_env(char ***envp, char *env)
{
	char	**getenv;
	int		i;

	i = 0;
	getenv = get_env(*envp, env, 0);
	if (*envp[1] == NULL && ft_strcmp(*envp[0], env) == 0)
		*envp[0] = NULL;
	if (!getenv)
		return (RN_ERR("Environment variable does not exist !\n"), -1);
	while (getenv[i] != NULL)
	{
		getenv[i] = getenv[i + 1];
		i++;
	}
	return (0);
}

char		**ft_cpy_env(char **env)
{
	int		cmp;
	char	**new_env;

	cmp = 0;
	while (env[cmp] != NULL)
		cmp++;
	new_env = ft_memalloc(sizeof(char *) * (cmp + 1));
	cmp = 0;
	while (env[cmp] != NULL)
	{
		new_env[cmp] = ft_strdup(env[cmp]);
		cmp++;
	}
	new_env[cmp] = NULL;
	return (new_env);
}
