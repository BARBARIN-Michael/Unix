/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 14:25:50 by mbarbari          #+#    #+#             */
/*   Updated: 2015/07/12 21:02:31 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int			launch_cmd(t_env *env)
{
	t_btree	*save;
	int		ret;

	save = env->bfirst;
	errno = 0;
	ret = 0;
	while (env->bfirst != NULL)
	{
		if (ft_multi_strcmp(2, env->bfirst->cde_name, "exit", "quit") == 0)
			return (ft_clear_btree(&save), 0);
		else if ((ft_multi_strcmp(5, env->bfirst->cde_name,
					"cd", "env", "setenv", "unsetenv", "$1")) != 0)
		{
			if ((ret = manage_cmd(env, &execve)) != 0)
				return (1);
		}
		else
			ret = ft_execve(env, env->bfirst);
		env->bfirst = env->bfirst->right;
	}
	if (save != NULL)
		ft_clear_btree(&save);
	return (1);
}

static int	ft_process(t_env *env)
{
	int		ret;
	t_btree	*environ;
	char	str[4096];
	char	*pwd;

	pwd = ft_get_pwd();
	environ = env->bfirst;
	env->bfirst = NULL;
	ft_set_env(&env->envp, "SHTXT", ft_nstrrchr((const char *)pwd, '/', 1));
	ft_printf("[%s%s%s] %s%s%s> ", C_BLUE, ft_get_env(env->envp, "NBR_SHELL"),
			C_NONE, C_CYAN, ft_get_env(env->envp, "SHTXT"), C_NONE);
	if ((ret = read(STDIN, str, 4096)) >= 4095)
		return (RN_ERR("Command too long to be parse!"), 0);
	if (ret == 0)
			return (0);
	if (ret < 0)
		return (RN_ERR("Cannot read command!"), 0);
	str[ret] = '\0';
	if (ft_strisempty(str) != 0)
	{
		if (ft_parser(str, env) < 0)
			return (env->bfirst ? ft_clear_btree(&env->bfirst) : 0, 1);
		return (free(pwd), launch_cmd(env));
	}
	return (free(pwd), 1);
}

static void	handle_sig(int sig)
{
	(void)sig;
	*SIGNAL = sig;
}

int			*singleton_signal(void)
{
	static int	signal;

	return (&signal);
}

void		ft_exec(t_env *env)
{
	signal(SIGINT, handle_sig);
	while (env->done)
	{
		if (!ft_get_env(env->envp, "PATH"))
			ft_set_env(&env->envp, "PATH",
								"/bin:/usr/bin:/usr/ucb:/usr/local/bin");
		*SIGNAL = 0;
		env->done = ft_process(env);
	}
}
