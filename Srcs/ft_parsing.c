/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:56:34 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 12:03:17 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static char		*ft_chgstr(char *str)
{
	static char		*val1[] = {"\\a", "\\b", "\\t", "\\n", "\\v", "\\r", NULL};
	static char		*val2[] = {"\a", "\b", "\t", "\n", "\v", "\r", NULL};
	char			*out;
	char			*tmp;
	int				cmp;

	cmp = 1;
	out = ft_strchange(str, val1[0], val2[0]);
	tmp = out;
	while (val1[cmp] != NULL)
	{
		if (ft_strstr(out, val1[cmp]))
		{
			out = ft_strchange(out, val1[cmp], val2[cmp]);
			free(tmp);
		}
		tmp = out;
		cmp++;
	}
	return (out);
}

static void		ft_lst_gestion(t_operand op, char *dst, t_env *env)
{
	t_lst_bdin	*elem;

	if (dst)
	{
		elem = ft_lst_sh_new(op, dst);
		free(dst);
	}
	else
		elem = ft_lst_sh_new(op, NULL);
	ft_lst_sh_addend(&env->lst_bdin, elem);
}

static int		ft_which_inc(t_operand op, int j, char c)
{
	if (op == o_pipe_d || op == o_and_d || op == o_red_dl || op == o_red_dr
			|| op == o_red_e || c == '"')
		return (j + 2);
	else
		return (j + 1);
}

static int		ft_check_end_string(char *str, int j)
{
	j = ft_wh3(str, j + 1);
	if (str[j] != '"')
		return (RN_ERR("Missing '\"' to end the string"), -1);
	return (j);
}

int				ft_parsing(char *str, t_env *env)
{
	int				j;
	int				i;
	char			*dst;
	t_operand		op;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i = ft_wh1(str, i);
		j = str[i] && str[i] != '"' ? ft_wh2(str, i) : i;
		if (str[j] && str[j] == '"')
			if ((j = ft_check_end_string(str, j)) < 0)
				return (-1);
		op = ft_which_op(&(str[i]));
		dst = NULL;
		if (op == o_string)
		{
			dst = (str[i] == '"') ? ft_chgstr(ft_strsub(str, i + 1, j - i - 1))
				: ft_strsub(str, i, j - i);
			j = str[j] != ' ' && str[j] != '\n' ? j - 1 : j;
		}
		(ft_lst_gestion(op, dst, env), i = ft_which_inc(op, j, str[i]));
	}
	return (0);
}
