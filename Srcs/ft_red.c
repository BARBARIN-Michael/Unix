/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:03:20 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/15 19:40:32 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		ft_pipe(t_env *env, t_btree *cmd, t_btree *file, t_exec exec)
{
	t_tabpid		pid;
	int				status;
	int				error;

	ft_bzero(&pid, sizeof(pid));
	if ((error = ft_exec_pipe(env, cmd, exec, &pid)) != 0)
		return (error);
/*	while (file && file->operand == o_pipe)
		if ((error = ft_exec_pipe(env, file, exec, &pid)) < 0)
			return (error);
		else
			file = file->left;
*/
	while (pid.id > 0)
	{
		waitpid(pid.pidbyfd[pid.id].pid, &status, 0);
		ft_putstr_fd(C_BROWN"\n======== JE SUIS DANS PAPA ==========", STDERR);
		close(pid.pidbyfd[pid.id].pipe[0]);
		ft_putstr_fd(C_RED"\nClose pipe IN: ", STDERR);
		ft_putstr_fd(ft_itoa(pid.pidbyfd[pid.id].pipe[1]), STDERR);

		if (pid.id == 1) {
			dup2(pid.pidbyfd[pid.id].pipe[1], STDIN);
			ft_putstr_fd(C_CYAN"\nDup pipe IN: ", STDERR);
			ft_putstr_fd(ft_itoa(pid.pidbyfd[pid.id].pipe[1]), STDERR);
			ft_putstr_fd(" dans fd : "C_NONE, STDERR);
			ft_putstr_fd(ft_itoa(STDIN), STDERR);
		}
		else {
			dup2(pid.pidbyfd[pid.id].pipe[1], pid.pidbyfd[pid.id - 1].pipe[1]);
			ft_putstr_fd(C_CYAN"\nDup pipe IN: ", STDERR);
			ft_putstr_fd(ft_itoa(pid.pidbyfd[pid.id].pipe[1]), STDERR);
			ft_putstr_fd(" dans fd : "C_NONE, STDERR);
			ft_putstr_fd(ft_itoa(pid.pidbyfd[pid.id - 1].pipe[1]), STDERR);
		}
		if ((error = test_exit(status)) != 0)
			while (pid.id > 0)
			(kill(pid.pidbyfd[pid.id - 1].pid, SIGKILL), --pid.id);
		dup2(pid.pidbyfd[pid.id - 1].pipe[0], pid.pidbyfd[pid.id - 2].pipe[0]);
		dup2(pid.pidbyfd[pid.id - 1].pipe[1], pid.pidbyfd[pid.id - 2].pipe[1]);
		--pid.id;
		if (pid.id == 0)
			break ;
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
