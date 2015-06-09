/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_format2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 14:51:19 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/05 13:07:59 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*add_precision(char *str, t_opt *opt, int mod)
{
	char	c;
	char	*s1;
	int		start;

	s1 = str;
	if (!opt->opt_dot)
		return (str);
	start = !ft_isdigit(*str) ? 1 : 0;
	c = ft_strchr("diupxXoO", mod) ? '0' : ' ';
	if (mod != 's' && (size_t)opt->precision > ft_strlen(str))
		s1 = ft_strset(str, start, opt->precision - ft_strlen(str) + start, c);
	else if (mod == 's' && (size_t)opt->precision < ft_strlen(str))
		return (ft_strsub(str, 0, opt->precision));
	else if (ft_strchr("diuxXoO", mod) && ft_atoi(str) == 0 &&
			(opt->opt_dot && (size_t)opt->precision < ft_strlen(str)))
		return (ft_strdup(""));
	return (s1);
}

char	*add_lenght(char *str, t_opt *opt, int mod)
{
	char	*s1;
	char	c;
	int		pos;
	int		offset;

	s1 = str;
	if (opt->lenght == 0)
		return (str);
	c = opt->opt_0 ? '0' : ' ';
	c = opt->opt_dot && (size_t)opt->precision == ft_strlen(str)
											&& ft_strchr("di", mod) ? ' ' : c;
	pos = 0;
	offset = ((*str == '-' || *str == '+' || *str == ' ') &&
			!ft_strchr("SC", mod)) ? 1 : 0;
	offset = (mod == 'p' || (ft_strchr("xX", mod) && opt->opt_sharp))
																? 2 : offset;
	pos = opt->opt_neg ? (int)ft_strlen(str) : pos;
	if ((size_t)opt->lenght > ft_strlen(str) && opt->opt_neg)
		s1 = ft_strset(str, pos, opt->lenght - ft_strlen(str), c);
	else if ((size_t)opt->lenght > ft_strlen(str) && opt->opt_0)
		s1 = ft_strset(str, pos + offset, opt->lenght - ft_strlen(str), c);
	else if ((size_t)opt->lenght > ft_strlen(str))
		s1 = ft_strset(str, pos, opt->lenght - ft_strlen(str), c);
	return (s1);
}
