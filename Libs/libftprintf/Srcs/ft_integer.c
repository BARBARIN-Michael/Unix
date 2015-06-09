/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:42:14 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/31 16:30:17 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>

char	*handle_fd(va_list ap, t_opt *opt)
{
	int		fd;

	fd = (int)va_arg(ap, intmax_t);
	opt->fd = fd;
	return (ft_strdup(""));
}

char	*handle_decimal(va_list ap, t_opt *opt)
{
	char	*str;

	if (opt->opt_type == opt_hh)
		str = ft_itoa((signed char)va_arg(ap, intmax_t));
	else if (opt->opt_type == opt_h)
		str = ft_itoa((short)va_arg(ap, intmax_t));
	else if (opt->opt_type == opt_l)
		str = ft_itoa((long)va_arg(ap, intmax_t));
	else if (opt->opt_type == opt_ll)
		str = ft_itoa((long long)va_arg(ap, intmax_t));
	else if (opt->opt_type == opt_j)
		str = ft_itoa((intmax_t)va_arg(ap, intmax_t));
	else if (opt->opt_type == opt_z)
		str = ft_itoa((size_t)va_arg(ap, intmax_t));
	else
		str = ft_itoa((int)va_arg(ap, int));
	if (ft_strcmp(str, "") == 0)
		return (ft_strdup("0"));
	return (ft_strdup(str));
}

char	*handle_uint(va_list ap, t_opt *opt)
{
	char	*str;

	if (opt->opt_type == opt_l)
		str = ft_utoa((unsigned long)va_arg(ap, uintmax_t));
	else if (opt->opt_type == opt_ll)
		str = ft_utoa((unsigned long long)va_arg(ap, uintmax_t));
	else if (opt->opt_type == opt_h)
		str = ft_utoa((unsigned short)va_arg(ap, uintmax_t));
	else if (opt->opt_type == opt_hh)
		str = ft_utoa((unsigned char)va_arg(ap, uintmax_t));
	else if (opt->opt_type == opt_j)
		str = ft_utoa((uintmax_t)va_arg(ap, uintmax_t));
	else if (opt->opt_type == opt_z)
		str = ft_utoa((size_t)va_arg(ap, uintmax_t));
	else
		str = ft_utoa((unsigned int)va_arg(ap, uintmax_t));
	if (ft_strcmp(str, "") == 0)
		return (ft_strdup("0"));
	return (ft_strdup(str));
}

char	*handle_oct(va_list ap, t_opt *opt)
{
	char	*str;

	str = ft_special(*opt, ap, BASE_8, &ft_ntoa);
	return (ft_strdup(str));
}
