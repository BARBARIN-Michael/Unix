/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 17:59:25 by mbarbari          #+#    #+#             */
/*   Updated: 2015/07/14 14:15:23 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static char	*handle_pwd(t_btree *btree, char *new_dir, char **env)
{
	char	directory[DEFAULT_MAX_LENGHT_PATH];

	getcwd(directory, DEFAULT_MAX_LENGHT_PATH);
	if (ft_strchr(new_dir, '/') != NULL)
		return (new_dir);
	else if (new_dir[0] == '-' && new_dir[1] == '\0')
		return (ft_get_env(env, "OLDPWD"));
	else if ((ft_array_count((void **)btree->args_tab) == 0))
		return (ft_get_env(env, "HOME"));
	else if (new_dir[0] == '~')
		return (ft_multi_strjoin(3, ft_get_env(env, "HOME"), "/", &new_dir[1]));
	else
		return (ft_multi_strjoin(3, directory, "/", new_dir));
}

int			ft_buildin_cd(t_btree *btree, char **envp)
{
	char	*dir;
	int		error;
	char	directory[DEFAULT_MAX_LENGHT_PATH];

	(error = 0, getcwd(directory, DEFAULT_MAX_LENGHT_PATH));
	if (ft_array_count((void **)btree->args_tab) > 2)
		return (RN_ERR("Too many arguements for command cd!\n"), -1);
	dir = (btree->args_tab[1] == NULL) ? handle_pwd(btree, "~", envp) :
		handle_pwd(btree, btree->args_tab[1], envp);
	if (access(dir, 0 | F_OK) != 0)
		return (RN_ERR("cd: %s: No such file of directory\n", dir), -1);
	else if (access(dir, 0 | F_OK | R_OK) != 0)
		return (ft_printf("cd: Permission denied: %s\n", dir), -1);
	else
	{
		if (chdir(dir) != 0)
			return (RN_ERR("cd:%s:%d :Unknow error\n", dir, error), -1);
		ft_set_env(&envp, "OLDPWD", directory);
		if (getcwd(directory, DEFAULT_MAX_LENGHT_PATH) == NULL)
			return (RN_ERR("cd:%s:error:%d :Unknow error\n", dir, error), -1);
		else
			ft_set_env(&envp, "PWD", directory);
	}
	return (0);
}
