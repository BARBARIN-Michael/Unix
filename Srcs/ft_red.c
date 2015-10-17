/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:03:20 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/17 19:33:35 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		ft_pipe(t_env *env, t_btree *cmd, t_btree *file, t_exec exec)
{
	t_tabpid		pid;
	int				status;
	int				error;
	t_btree			*tree;
	int				i;

	ft_bzero(&pid, sizeof(t_tabpid));
	tree = cmd;
	while (tree)
	{
		pipe(pid.pidbyfd[pid.id].pipe);
		tree = tree->left;
		++pid.id;
	}
	i = pid.id - 1;
	while (cmd)
	{
		--pid.id;
		if ((error = ft_exec_pipe(env, cmd, exec, &pid)) < 0)
			return (error);
		cmd = cmd->left;
	}
	pid.id = i;
	while (pid.id >= 0)
	{
		ft_printf(C_BLUE"Waiting for %d\n", pid.pidbyfd[pid.id].pid);
		waitpid(pid.pidbyfd[pid.id].pid, &status, 0);
		ft_printf(C_CYAN"DONE !\n");
		//if ((error = test_exit(status)) != 0)
		//	while (pid.id > 0)
		//		(kill(pid.pidbyfd[pid.id - 1].pid, SIGKILL), --pid.id);
		--pid.id;
		ft_printf(C_GREEN"prepare to wait id[%d] = %d\n", pid.id, pid.pidbyfd[pid.id].pid);
	}
	return (error);
}

int		ft_red_dl(t_env *env, t_btree *cmd, t_btree *file, t_exec exec)
{
	int		fd_pipe[2];
	int		ret;
	char	str[4096];

	((void)cmd, (void)exec, (void)env);
	if ((env->fd_backup[STDIN] = dup(STDIN)) < 0)
		return (RN_ERR("Cannot duplicate STDIN(0)!\n"), -1);
	pipe(fd_pipe);
	while (1)
	{
		ft_printf("%sheredoc>%s", BLUE, C_NONE);
		if ((ret = read(STDIN, str, 4095)) < 0)
			return (RN_ERR("Cannot read into STDIN!\n"), -1);
		str[ret] = '\0';
		if (ft_strcmp(str, file->cde_name) == 10)
			break ;
		else
			ft_putstr_fd(str, fd_pipe[1]);
	}
	if (dup2(fd_pipe[0], STDIN) < 0)
		return (RN_ERR("Cannot create dup!\n"), -1);
	return (close(fd_pipe[1]), close(fd_pipe[0]), 0);
}

int		ft_red_l(t_env *env, t_btree *cmd, t_btree *file, t_exec exec)
{
	int		fd_file;

	((void)cmd, (void)exec);
	if (env->fd_backup[STDIN] != STDIN)
	{
		RN_ERR("Ambigous redirection! (< %s ignored)\n", file->cde_name);
		return (0);
	}
	if ((env->fd_backup[STDIN] = dup(STDIN)) < 0)
		return (RN_ERR("Cannot duplicate STDIN(0)!\n"), -1);
	if ((fd_file = open(file->cde_name, O_RDONLY)) < 0)
		return (RN_ERR("Cannot open file %s\n", file->cde_name), -1);
	if (dup2(fd_file, STDIN) < 0)
		return (RN_ERR("Cannot create dup!\n"), -1);
	close(fd_file);
	return (0);
}

int		ft_red_r(t_env *env, t_btree *cmd, t_btree *file, t_exec exec)
{
	int		fd_file;

	((void)cmd, (void)exec);
	if (env->fd_backup[STDOUT] != STDOUT)
	{
		RN_ERR("Ambigous redirection! (> %s ignored)\n", file->cde_name);
		return (0);
	}
	if ((env->fd_backup[STDOUT] = dup(STDOUT)) < 0)
		return (RN_ERR("Cannot duplicate STDIN(0)!\n"), -1);
	if ((fd_file = open(file->cde_name, OPTION_FILE | O_TRUNC, 0644)) < 0)
		return (RN_ERR("Cannot open file %s\n", file->cde_name), -1);
	if (dup2(fd_file, STDOUT) < 0)
		return (RN_ERR("Cannot create dup!\n"), -1);
	close(fd_file);
	return (0);
}

int		ft_red_dr(t_env *env, t_btree *cmd, t_btree *file, t_exec exec)
{
	int		fd_file;

	((void)cmd, (void)exec);
	if (env->fd_backup[STDOUT] != STDOUT)
	{
		RN_ERR("Ambigous redirection! (>> %s ignored)\n", file->cde_name);
		return (0);
	}
	if ((env->fd_backup[STDOUT] = dup(STDOUT)) < 0)
		return (RN_ERR("Cannot duplicate STDIN(0)!\n"), -1);
	if ((fd_file = open(file->cde_name, OPTION_FILE | O_APPEND, 0644)) < 0)
		return (RN_ERR("Cannot open file %s\n", file->cde_name), -1);
	if (dup2(fd_file, STDOUT) < 0)
		return (RN_ERR("Cannot create dup!\n"), -1);
	close(fd_file);
	return (0);
}
