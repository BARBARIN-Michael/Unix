/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 17:35:19 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/20 11:51:13 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		ft_pipe(t_env *env, t_btree *cmd, t_btree *file, t_exec exec)
{
	int		fd[2];
	pid_t	pid;
	int		ret;
	int		status;

	ret = 0;
	(void)file;
	if (pipe(fd) == -1)
		return (RN_ERR("Cannot create new pipeline!"), -1);
	if ((pid = fork()) == -1)
		return (RN_ERR("Cannot create new fork"), -1);
	if (pid != 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ret = ft_exec_str(env, cmd, exec);
		exit(-1);
	}
	close(fd[1]);
	dup2(fd[0], 0);
	waitpid(pid, &status, 0);
	if (cmd->left != NULL)
		ft_pipe(env, cmd->left, NULL, exec);
	return (0);
}
