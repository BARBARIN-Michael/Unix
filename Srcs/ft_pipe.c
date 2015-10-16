/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 17:35:19 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/16 17:41:38 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

int		ft_pipe(t_env *env, t_btree *cmd, t_btree *file, t_exec exec)
{
	int		fd_pipe[2];
	pid_t	pid1;
	pid_t	pid2;
	int		ret;

	ft_bzero(pid1, sizeof(pid1) * 3);
	if (pipe(fd_pipe) == -1)
		return (RN_ERR("Cannot create pipe\n"), -1);
	pid1 == 0 ? pipe_by_father(fd_pipe, env, cmd, exec) :
		pipe_by_son(fd_pipe, env, cmd, exec);
}

