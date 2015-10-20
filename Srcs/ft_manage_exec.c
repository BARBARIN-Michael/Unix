/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 02:52:43 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/20 19:15:57 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>
#include <errno.h>

int			ft_str(t_env *env, t_btree *l, t_btree *r, t_exec exec)
{
	pid_t		pid;
	int			error;
	int			status;

	error = 0;
	(void)r;
	error = ft_exec_str(env, l, exec);
	return (error);
}

int			ft_execve(t_env *env, t_btree *tree)
{
	if ((tree->error == 1 && tree->operand == o_and_d) ||
			(tree->error == 0 && tree->operand == o_pipe_d))
		return (0);
	if (ft_strcmp(tree->cde_name, "cd") == 0)
		ft_buildin_cd(tree, env->envp);
	else if (ft_strcmp(tree->cde_name, "env") == 0)
	{
		if (tree->args_tab[1] == NULL || ft_strcmp(tree->args_tab[1], "") == 0)
			ft_print_env(env->envp);
		else
			ft_printf("%s%s%s%s %s%s\n", BLUE, tree->args_tab[1], C_NONE,
					C_BROWN, ft_get_env(env->envp, tree->args_tab[1]), C_NONE);
	}
	else if (ft_strcmp(tree->cde_name, "setenv") == 0)
	{
		if (!tree->args_tab[1] && !tree->args_tab[2])
			return (RN_ERR("Setenv need two params!\n"), -1);
		ft_set_env(&env->envp, tree->args_tab[1], tree->args_tab[2]);
	}
	else if (ft_strcmp(tree->cde_name, "unsetenv") == 0)
		if (ft_unset_env(&env->envp, tree->args_tab[1]) < 0)
			return (-1);
	ft_printerr(env, tree);
	return (0);
}

int			ft_exec_str(t_env *env, t_btree *tree, t_exec exec)
{
	pid_t	pid;
	int		status;
	char	*fct;

	if ((tree->error >= 1 && tree->operand == o_and_d) ||
			(tree->error == 0 && tree->operand == o_pipe_d))
		return (0);
	if (exec == &execve && !(fct = command_path(env, tree->cde_name)))
	{
		RN_ERR("Cannot find function %s\n", tree->cde_name), free(fct);
		return (-1);
	}
	else if (!tree->args_tab)
		return (RN_ERR("Table des arguements vide!"), free(fct), -1);
	if ((pid = fork()) == 0)
	{
		exec(fct, ft_star(env, tree->args_tab), env->envp);
		(RN_ERR("Cannot execute function %s", tree->cde_name), exit(1));
	}
	else
	{
		waitpid(pid, &status, WUNTRACED), free(fct);
		return (test_exit(status));
	}
	return (0);
}

int			ft_exec_pipe(t_env *env, t_btree *tree, t_exec exec, t_tabpid *pid)
{
	int			status;
	char		*fct;
	int			fdtmp;
	int			cmp;

	if ((tree->error >= 1 && tree->operand == o_and_d) ||
			(tree->error == 0 && tree->operand == o_pipe_d))
		return (0);
	else if (exec == &execve && !(fct = command_path(env, tree->cde_name)))
		return (RN_ERR("Cannot find function %s\n", tree->cde_name),
				free(fct), -1);
	else if (!tree->args_tab)
		return (RN_ERR("Table des arguements vide!"), free(fct), -1);
	exec(fct, ft_star(env, tree->args_tab), env->envp);
	return (0);
}
