/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3quarter_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 11:24:10 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 14:20:30 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <ft_checking.h>

char	*handle_lenght(char *s1, t_opt *opt)
{
	int		cmp;
	char	*str;

	cmp = 0;
	while (ft_isdigit(s1[cmp]))
		cmp++;
	str = ft_strsub(s1, 0, cmp);
	opt->lenght = ft_atoi(str);
	free(str);
	s1 += cmp;
	return (s1);
}

char	*handle_dot(char *s1, t_opt *opt)
{
	int		cmp;
	char	*str;

	cmp = 0;
	opt->opt_dot = 1;
	if (opt->opt_base > opt->opt_dot)
	{
		N_ERR("ft_printf : Bad order of flags %s", s1);
		return (opt->error = -1, NULL);
	}
	if (s1[1] == '*')
		return (handle_star(opt, 1), &s1[2]);
	opt->opt_base = opt->opt_base & opt->opt_dot;
	while (ft_isdigit(s1[1 + cmp]))
		cmp++;
	str = ft_strsub(s1, 1, cmp);
	opt->precision = ft_atoi(str);
	if (cmp == 0)
		opt->precision = 0;
	free(str);
	return (&s1[1 + cmp]);
}

char	*handle_neg(char *s1, t_opt *opt)
{
	opt->opt_neg = 1;
	if (opt->opt_base > opt->opt_neg)
	{
		N_ERR("ft_printf : Bad order of flags %s", s1);
		return (opt->error = -1, NULL);
	}
	opt->opt_base = opt->opt_base & opt->opt_neg;
	if (opt->opt_0 == 1)
		opt->opt_0 = 0;
	return (&s1[1]);
}

char	*handle_pos(char *s1, t_opt *opt)
{
	opt->opt_pos = 1;
	if (opt->opt_base > opt->opt_pos)
	{
		N_ERR("ft_printf : Bad order of flags %s", s1);
		return (opt->error = -1, NULL);
	}
	opt->opt_base = opt->opt_base & opt->opt_pos;
	return (&s1[1]);
}

char	*handle_space(char *s1, t_opt *opt)
{
	opt->opt_space = 1;
	if (opt->opt_base > opt->opt_space)
	{
		N_ERR("ft_printf : Bad order of flags %s", s1);
		return (opt->error = -1, NULL);
	}
	opt->opt_base = opt->opt_base & opt->opt_space;
	return (&s1[1]);
}
