/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 23:21:02 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/01 23:24:04 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void ft_fill_std_env(char **env, char *varenv, char *newvar)
{
	if (!ft_getenv(env, varenv))
		ft_set_env(&env, varenv, newvar);
}

static void ft_fill_spe_lvl(char **env)
{
	int		newlvl;

	if (!ft_getenv("SHLVL", env))
		setenv("SHLVL", "1")
	else
	{
		newlvl = ft_atoi(ft_getenv("SHLVL", envp)) + 1;
		setenv("SHLVL",	ft_itoa(newlvl), envp);
	}
}

char	**ft_fill_env(char *opt)
{
	extern char **environ;
	char		**new_env;

	if (opt == NULL || !ft_strchr(opt, 'i'))
		new_env = ft_cpy_env(environ);
	else
		new_env = ft_memalloc(sizeof(char *));
	ft_fill_std_env(new_env, "PATH", "/usr/local/bin:/usr/bin:/bin:"); 
	ft_fill_std_env(new_env, "USER", "Anonymous"); 
	ft_fill_std_env(new_env, "SHELL", "ft_sh"); 
	ft_fill_spe_lvl(new_env);
	return (new_env);
}
