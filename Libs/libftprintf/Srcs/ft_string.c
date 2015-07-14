/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:37:32 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 14:15:56 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <ft_checking.h>

char	*handle_str(va_list ap, t_opt *opt)
{
	char	*str;

	if (opt->opt_type == opt_l)
		return (handle_wstr(ap, opt));
	else if (opt->opt_type != opt_none)
		opt->error = -1;
	if (!(str = (char *)va_arg(ap, char *)))
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char	*handle_wstr(va_list ap, t_opt *opt)
{
	wchar_t			*c;
	char			*str;
	int				try;

	opt->opt_wchar = 1;
	try = 0;
	if (!(c = (wchar_t *)va_arg(ap, wchar_t *)))
		return (ft_strdup("(null)"));
	str = ft_strnew(1);
	str[0] = '\0';
	while (*c)
	{
		if (opt->opt_dot && ((opt->precision -= ft_wlen(*c)) < 0))
			break ;
		try == 0 ? str[0] = '\0' : 0;
		try = 1;
		CHECK_MEM((str = ft_strjoin(str, ft_wtoa(*c))));
		c++;
	}
	opt->precision = 0;
	if (ft_strcmp(str, " ") == 0 && *c == '\0')
		return (ft_strdup(""));
	return (ft_strdup(str));
}

char	*handle_wchar(va_list ap, t_opt *opt)
{
	wint_t			c;
	char			*str;

	opt->opt_wchar = 1;
	c = (wint_t)va_arg(ap, wint_t);
	if (c == 0)
		return (ft_strdup("\0"));
	str = ft_wtoa(c);
	return (ft_strdup(str));
}

char	*handle_char(va_list ap, t_opt *opt)
{
	char	*c;

	if (opt->opt_type == opt_l)
		return (handle_wchar(ap, opt));
	else if (opt->opt_type != opt_none)
		opt->error = -1;
	if (!(c = malloc(2)))
		RN_ERR("Malloc error into handle_char!", NULL);
	c[0] = (char)va_arg(ap, int);
	c[1] = '\0';
	return (c);
}

char	*handle_percent(va_list ap, t_opt *opt)
{
	char	*c;

	(void)ap;
	(void)opt;
	if (!(c = malloc(2)))
		RN_ERR("Malloc error into handle_percent!", NULL);
	c[0] = '%';
	c[1] = '\0';
	return (c);
}
