/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 15:20:14 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/24 18:28:39 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_special(t_opt opt, va_list ap, char *base, t_fcts_spe spe)
{
	if (opt.opt_type == opt_l)
		return (spe((unsigned long)va_arg(ap, uintmax_t), base));
	else if (opt.opt_type == opt_ll)
		return (spe((unsigned long long)va_arg(ap, uintmax_t), base));
	else if (opt.opt_type == opt_h)
		return (spe((unsigned short)va_arg(ap, uintmax_t), base));
	else if (opt.opt_type == opt_hh)
		return (spe((unsigned char)va_arg(ap, uintmax_t), base));
	else if (opt.opt_type == opt_j)
		return (spe((uintmax_t)va_arg(ap, uintmax_t), base));
	else if (opt.opt_type == opt_z)
		return (spe((size_t)va_arg(ap, uintmax_t), base));
	else
		return (spe((unsigned int)va_arg(ap, uintmax_t), base));
}

char	*ft_format(char *s1, t_opt opt, int mod)
{
	char			*str;

	str = s1;
	str = add_precision(str, &opt, mod);
	str = add_sharp(str, &opt, mod);
	str = add_pos(str, &opt, mod);
	str = add_0(str, &opt, mod);
	str = add_space(str, &opt, mod);
	str = add_lenght(str, &opt, mod);
	if ((mod == 'c' || mod == 'C') && *s1 == '\0' && ft_strlen(str) > 1)
		str[ft_strlen(str) - 1] = '\0';
	return (str);
}
