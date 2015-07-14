/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 09:06:21 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 11:35:58 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int	testing_star(char **args)
{
	int		cmp;

	cmp = 0;
	while (args[cmp] != NULL)
	{
		if (ft_strchr(args[cmp], '*') != NULL)
			return (1);
		cmp++;
	}
	return (0);
}

static void	ft_del(char **tab_args)
{
	int		cmp;

	cmp = 0;
	while (tab_args[cmp] != NULL)
	{
		free(tab_args[cmp]);
		cmp++;
	}
	free(tab_args);
}

static int	star_match(char *s1, char *s2)
{
	if (*s1 != '\0' && *s2 == '*')
		return (star_match(s1 + 1, s2) + star_match(s1, s2 + 1));
	if (*s1 == '\0' && *s2 == '*')
		return (star_match(s1, s2 + 1));
	if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
		return (star_match(s1 + 1, s2 + 1));
	if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}

static int	get_filestar(char **new_args, t_env *env, char *args, size_t n)
{
	DIR				*d_dir;
	struct dirent	*od;
	char			*dir;
	size_t			cmp;

	dir = NULL;
	if ((cmp = ft_nstrrchr(args, '/', 1) - args) > 0)
	{
		dir = ft_strndup(args, cmp);
		d_dir = opendir(dir);
	}
	cmp = 0;
	if ((!dir && !(d_dir = opendir(ft_get_env(env->envp, "PWD")))))
		return (RN_ERR("opendir failed with %p\n", dir), 1);
	while ((od = readdir(d_dir)) != NULL && cmp < n)
	{
		if (star_match(od->d_name, dir ? ft_nstrrchr(args, '/', 1) + 1 : args))
		{
			new_args[cmp] = (!dir) ? ft_strdup(od->d_name) :
				ft_multi_strjoin(3, dir, "/", od->d_name);
			cmp++;
		}
	}
	return (closedir(d_dir), cmp);
}

char		**ft_star(t_env *env, char **args)
{
	char	**nargs;
	int		cp[3];

	if (testing_star(args) == 0)
		return (args);
	(ft_bzero(cp, sizeof(int) * 3));
	nargs = ft_memalloc(sizeof(char *) * 26);
	while (args[cp[0]] != NULL)
	{
		if (ft_strchr(args[cp[0]], '*') == NULL && cp[1] < 25)
			(nargs[cp[1]] = ft_strdup(args[cp[0]]), cp[1]++);
		else if (cp[1] >= 25)
			return (RN_ERR("Troncage des directions!"), ft_del(args), nargs);
		else
		{
			nargs[cp[1]] = args[cp[0]];
			cp[1] += get_filestar(&nargs[cp[1]], env, args[cp[0]], 25 - cp[1]);
		}
		++cp[0];
	}
	return (ft_del(args), nargs);
}
