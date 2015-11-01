/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 14:51:58 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/05 13:06:28 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*add_0(char *str, t_opt *opt, int mod)
{
	if (opt->opt_0 && !opt->opt_neg && (size_t)opt->lenght > ft_strlen(str) &&
			(ft_strchr("diouxX", mod) && opt->precision == 0)
			&& ft_atoi(str) != 0)
	{
		if (opt->opt_dot && (size_t)opt->precision == ft_strlen(str)
				&& ft_strchr("di", mod))
			return (str);
		if (ft_isdigit(*str))
			return (ft_strjoin_free("0", str, 'r'));
	}
	return (str);
}

char	*add_sharp(char *str, t_opt *opt, int mod)
{
	char hexa[3];

	ft_insert(hexa, 2, "0");
	if ((ft_strchr("oOxX", mod) && !opt->opt_sharp)
			|| !ft_strchr("xXoOp", mod))
		return (str);
	if (mod == 'p' || (mod == 'x' && opt->opt_sharp))
		ft_insert(hexa, 3, "0x");
	else if (mod == 'X' && opt->opt_sharp)
		ft_insert(hexa, 3, "0X");
	if (mod == 'p' && ft_atoi(str) == 0
			&& (opt->opt_dot && opt->precision == 0))
		return (ft_strdup("0x"));
	else if (ft_strchr("xX", mod) && (*str == '0' && *(str + 1) == '\0'))
		return (str);
	else if (ft_strchr("oO", mod) && (*str == '0'))
		return (str);
	else if (ft_strchr("xX", mod) && *str == 0)
		return (ft_strdup(""));
	return (ft_strjoin_free(hexa, str, 'r'));
}

char	*add_pos(char *str, t_opt *opt, int mod)
{
	char *s1;

	if (opt->opt_pos && ft_strchr("diD", mod) && ft_isdigit(*str))
	{
		opt->opt_space = 0;
		s1 = ft_strjoin_free("+", str, 'n');
		return (s1);
	}
	return (str);
}

char	*add_space(char *str, t_opt *opt, int mod)
{
	if (opt->opt_space && ft_strchr("di", mod) && ft_isdigit(*str)
			&& opt->opt_pos == 0)
		return (ft_strjoin_free(" ", str, 'r'));
	return (str);
}
