/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 23:27:57 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/01 23:45:51 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static char			*is_absolute_directory(t_env *env, char *cmd)
{
	if (((ft_strchr(cmd, '/') != NULL)))
		return (cmd);
	else if ((ft_strncmp(cmd, "./", 2) == 0 || *cmd == '~'))
		return ((ft_strjoin(ft_get_env(env->envp, "HOME"), cmd)));
	return (NULL);
}

static char			*is_path_directory(t_env *env, char *cmd)
{
	char	**ptr;
	char	*path;
	size_t	i;

	i = 0;
	if ((ptr = ft_ptrsplit(ft_get_env(env->envp, "PATH"), ':')))
	{
		while (ptr[i] != NULL)
		{
			path = ft_multi_strjoin(3, ptr[i], "/", cmd);
			if (access(path, 0 | F_OK | X_OK) == 0)
				return (free(ptr), path);
			free(path);
			++i;
		}
	}
	free(ptr);
}

char			*command_path(t_env *env, char *cmd)
{
	char	*str;

	if ((path = is_absolute_directory(env, cmd) != NULL))
		return (path);
	if (str = is_path_directory(env, cmd) && access(str, 0 | F_OK | X_OK) == 0)
		return (path);
	return (NULL);
}
