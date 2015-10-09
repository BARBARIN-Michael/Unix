/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 14:12:32 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/09 13:40:42 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static t_env	ft_init_env(char **envp)
{
	t_env	env;
	char	*getenv;
	int		i;
	char	*pwd;

	i = 0;
	if ((getenv = ft_get_env(envp, "NBR_SHELL")) == NULL)
		ft_set_env(&envp, "NBR_SHELL", "1");
	else
		ft_set_env(&envp, "NBR_SHELL", ft_itoa(ft_atoi(getenv) + 1));
	pwd = ft_get_pwd();
	ft_set_env(&envp, "PWD", pwd);
	free(pwd);
	env = (t_env) {.done = 1, .envp = envp};
	return (env);
}

int				main(int ac, char **av, char **envp)
{
	int		cmp;
	t_env	env;
	char	**new_env;

	cmp = 1;
	(void)ac;
	(void)av;
	new_env = ft_cpy_env(envp);
	env = ft_init_env(new_env);
	ft_exec(&env);
	ft_tabdel(env.envp);
	free(env.envp);
	return (0);
}
