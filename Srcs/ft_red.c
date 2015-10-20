/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:03:20 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/20 19:16:47 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		ft_pipe(t_env *env, t_btree *cmd, t_btree *file, t_exec exec)
{
	int		p[2];
	pid_t	pid;
	int		fd_in;
	int		ret;

	fd_in = 0;
	while (cmd != NULL)
	{
		pipe(p);
		if ((pid = fork()) == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			dup2(fd_in, 0); //change the input according to the old one 
			if (cmd->left != NULL)
				dup2(p[1], 1);
			close(p[0]);
			ft_exec_pipe(env, cmd, exec, NULL);
			exit(EXIT_FAILURE);
		}
		waitpid(pid, &ret, WUNTRACED);
		close(p[1]);
		fd_in = p[0]; //save the input for the next command
		if ((ret = test_exit(ret)) != 0)
			return (ret);
		cmd = cmd->left;
	}
	return (0);
}

int		ft_red_dl(t_env *env, t_btree *cmd, t_btree *file, t_exec exec)
{
	int		fd_pipe[2];
	int		ret;
	char	str[4096];

	((void)cmd, (void)exec);
	if (env->fd_backup[STDIN] != STDIN)
	{
		RN_ERR("Ambigous redirection! (<< %s ignored)\n", file->cde_name);
		return (0);
	}
	pipe(fd_pipe);
	while (1)
	{
		ft_printf("%sheredoc>%s", BLUE, C_NONE);
		if ((ret = read(STDIN, str, 4095)) <= 0)
			return (RN_ERR("Cannot read into STDIN!\n"), -1);
		str[ret] = '\0';
		if (ft_strcmp(str, file->cde_name) == 10)
			break ;
		else
			ft_putstr_fd(str, fd_pipe[1]);
	}
	if (dup2(fd_pipe[0], STDIN) < 0)
		return (ft_printf("Cannot create dup!"), -1);
	return (close(fd_pipe[1]), 0);
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
