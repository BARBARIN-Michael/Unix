/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:03:20 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 11:32:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		ft_pipe(t_env *env, t_btree *cmd, t_btree *file, t_exec exec)
{
	int		fd_save[2];
	int		fd_pipe[2];

	pipe(fd_pipe);
	fd_save[0] = dup(STDOUT);
	fd_save[1] = dup(STDIN);
	if (fork() == 0)
	{
		close(fd_pipe[0]);
		dup2(fd_pipe[1], STDOUT);
		ft_exec_str(env, cmd, exec);
		exit(0);
	}
	else
	{
		close(fd_pipe[1]);
		dup2(fd_pipe[0], STDIN);
		ft_exec_str(env, file, exec);
		wait(NULL);
	}
	(dup2(fd_save[0], STDOUT), dup2(fd_save[1], STDIN));
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
		if (ft_strcmp(str, file->cde_name) == 0)
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
