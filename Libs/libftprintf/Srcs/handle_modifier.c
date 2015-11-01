/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1quarter_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:14:04 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/24 15:09:39 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*handle_l(char *s1, t_opt *opt)
{
	if (s1[1] == 'l')
	{
		opt->opt_type = opt_ll;
		return (&s1[2]);
	}
	opt->opt_type = opt_l;
	return (&s1[1]);
}

char	*handle_h(char *s1, t_opt *opt)
{
	if (s1[1] == 'h')
	{
		opt->opt_type = opt_hh;
		return (&s1[2]);
	}
	opt->opt_type = opt_h;
	return (&s1[1]);
}

char	*handle_j(char *s1, t_opt *opt)
{
	opt->opt_type = opt_j;
	return (&s1[1]);
}

char	*handle_z(char *s1, t_opt *opt)
{
	opt->opt_type = opt_z;
	return (&s1[1]);
}
