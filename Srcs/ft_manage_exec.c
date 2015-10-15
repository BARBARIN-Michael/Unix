/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 02:52:43 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/15 19:26:57 by mbarbari         ###   ########.fr       */
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
	int			status;
	char		*fct;
	pid_t		pid;

	if ((tree->error >= 1 && tree->operand == o_and_d) ||
			(tree->error == 0 && tree->operand == o_pipe_d))
		return (0);
	else if (exec == &execve && !(fct = command_path(env, tree->cde_name)))
		return (RN_ERR("Cannot find function %s\n", tree->cde_name),
				free(fct), -1);
	else if (!tree->args_tab)
		return (RN_ERR("Table des arguements vide!"), free(fct), -1);
	if (fork() == 0)
	{
		exec(fct, ft_star(env, tree->args_tab), env->envp);
		return (RN_ERR("Cannot exec function %s", tree->cde_name), -1);
	}
	else
		return (waitpid(pid, &status, WUNTRACED), free(fct), test_exit(status));
	return (free(fct), 0);
}

int			ft_exec_pipe(t_env *env, t_btree *tree, t_exec exec, t_tabpid *pid)
{
	int			status;
	char		*fct;
	int			fdtmp;


	ft_putstr_fd(C_NONE"EXCUTION DE LA COMMANDE :", STDERR);
	ft_putstr_fd(tree->cde_name, STDERR);

	//On recupere le dernier fd de sortie (si first stdout sinon l'ancien pipe
	ft_putstr_fd("\n\nTest 1 : ", STDERR);
	if (++pid->id == 1) {
		fdtmp = STDOUT;
		ft_putstr_fd("stdout\n", STDERR);
	}
	else {
		fdtmp = pid->pidbyfd[pid->id - 1].pipe[0];
		ft_putstr_fd("pipe : ", STDERR);
		ft_putstr_fd(ft_itoa(pid->pidbyfd[pid->id - 1].pipe[0]), STDERR);
	}
	
	//On cree un nouveau pipe pour inserer les data de la commande
	pipe(pid->pidbyfd[pid->id].pipe);
	ft_putstr_fd(C_GREEN"\nCreation d'un pipe: ", STDERR);
	ft_putstr_fd(ft_itoa(pid->pidbyfd[pid->id].pipe[1]), STDERR);
	ft_putstr_fd(" ----------> ", STDERR);
	ft_putstr_fd(ft_itoa(pid->pidbyfd[pid->id].pipe[0]), STDERR);
	ft_putstr_fd("\n", STDERR);

	//Gestion d'erreur, sans interet dans notre test
	if ((tree->error >= 1 && tree->operand == o_and_d) ||
			(tree->error == 0 && tree->operand == o_pipe_d))
		return (0);

	//Recuperation de la commande executable, est tjs vrai dans notre test
	else if (exec == &execve && !(fct = command_path(env, tree->cde_name)))
		return (RN_ERR("Cannot find function %s\n", tree->cde_name),
				free(fct), -1);

	//Si pas d'arguement, sera tjs vrai dans le test
	else if (!tree->args_tab)
		return (RN_ERR("Table des arguements vide!"), free(fct), -1);

	//Fonction qui nous interesse, cree un nouveau fork sur la nouvelle commande
	else if ((pid->pidbyfd[pid->id].pid = fork()) == 0)
	{
		ft_putstr_fd(C_BROWN"\n======== JE SUIS DANS FISTON ==========", STDERR);
		close(pid->pidbyfd[pid->id].pipe[0]);
		ft_putstr_fd(C_RED"\nClose pipe OUT: ", STDERR);
		ft_putstr_fd(ft_itoa(pid->pidbyfd[pid->id].pipe[0]), STDERR);
		ft_putstr_fd(C_CYAN"\nDup pipe IN: ", STDERR);
		ft_putstr_fd(ft_itoa(fdtmp), STDERR);
		ft_putstr_fd(" dans fd : "C_NONE, STDERR);
		ft_putstr_fd(ft_itoa(pid->pidbyfd[pid->id].pipe[1]), STDERR);
		dup2(pid->pidbyfd[pid->id].pipe[1], fdtmp);
		exec(fct, ft_star(env, tree->args_tab), env->envp);
		return (RN_ERR("Cannot exec function %s", tree->cde_name), -1);
	}
	return (0);
}
