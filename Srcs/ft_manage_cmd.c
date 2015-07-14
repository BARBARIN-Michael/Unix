/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 20:04:46 by mbarbari          #+#    #+#             */
/*   Updated: 2015/07/14 14:24:47 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>
#include <errno.h>

void			error_management(t_env *env, int err)
{
	if (env->bfirst->right)
		if (env->bfirst->right->error == 0)
			env->bfirst->right->error = err;
	env->error = err;
}

static int		test_pipe(t_btree *tree)
{
	t_btree		*save;

	save = tree;
	while (save != NULL)
	{
		if (save->operand == o_pipe)
			return (1);
		save = save->left;
	}
	return (0);
}

static void		manage_fd(t_env *env, int state)
{
	int	i;

	i = 0;
	if (state == 1)
	{
		while (i < 3)
		{
			env->fd_backup[i] = i;
			++i;
		}
	}
	else if (state == 2)
	{
		while (i < 3)
		{
			if (env->fd_backup[i] != i)
			{
				dup2(env->fd_backup[i], i);
				close(env->fd_backup[i]);
				env->fd_backup[i] = i;
			}
			++i;
		}
	}
}

int				manage_cmd(t_env *env, t_exec exec)
{
	static t_uchar		is_setup = 0;
	char				ret;
	t_btree				*tree;

	manage_fd(env, 1);
	is_setup = is_setup == 0 ? ft_setup_pipeline(env->pipe) : 1;
	if (!(tree = env->bfirst->left))
	{
		ret = env->pipe[env->bfirst->operand]
			(env, env->bfirst, NULL, exec);
		error_management(env, ret);
		return (manage_fd(env, 2), 0);
	}
	while (tree != NULL)
	{
		ret = env->pipe[tree->operand](env, env->bfirst, tree, exec);
		error_management(env, ret);
		if (ret < 0)
			break ;
		tree = tree->left;
	}
	if (test_pipe(env->bfirst) == 0 && ret >= 0)
		ft_exec_str(env, env->bfirst, exec);
	return (manage_fd(env, 2), ret);
}

char			*command_path(t_env *env, char *cmd)
{
	char	*path;
	char	**ptr;
	size_t	i;

	i = 0;
	if ((path = (ft_strchr(cmd, '/') != NULL) ? ft_strdup(cmd) : NULL))
		return (path);
	else if ((ft_strncmp(cmd, "./", 2) == 0 || *cmd == '~'))
		return ((path = ft_strjoin(ft_get_env(env->envp, "HOME"), cmd)));
	else if ((ptr = ft_strsplit(ft_get_env(env->envp, "PATH"), ':')))
	{
		while (ptr[i] != NULL)
		{
			path = ft_multi_strjoin(3, ptr[i], "/", cmd);
			if (access(path, 0 | F_OK | X_OK) == 0)
				return (ft_tabdel(ptr), path);
			free(path);
			++i;
		}
		ft_tabdel(ptr);
	}
	else if (path != NULL && access(path, 0 | F_OK | X_OK) == 0)
		return (path);
	return (NULL);
}
