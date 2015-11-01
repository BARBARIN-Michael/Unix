
#include <ft_sh.h>

void		ft_set_env(char ***envp, char *env, char *new)
{
	char	**getenv;
	char	**new_env;
	int		len;

	getenv = get_env(*envp, env, 0);
	if (!getenv)
	{
		if (!new)
			return ;
		len = ft_array_count((void **)*envp);
		new_env = ft_tabcpy_by_ptr(*envp, 2);
		new_env[len] = ft_multi_strjoin(3, env, "=", new);
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
	ft_strcmp(*envp[0], env);
	if (envp[1] && *envp[1] == NULL && ft_strcmp(*envp[0], env) == 0)
		return (*envp[0] = NULL, 0);
	else if (!getenv)
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
