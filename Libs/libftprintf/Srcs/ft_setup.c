/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 10:54:23 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 17:20:59 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	setup_flag(t_fcts_flag *fct_flag)
{
	fct_flag['l'] = &handle_l;
	fct_flag['j'] = &handle_j;
	fct_flag['h'] = &handle_h;
	fct_flag['z'] = &handle_z;
	fct_flag['#'] = &handle_sharp;
	fct_flag['0'] = &handle_0;
	fct_flag[' '] = &handle_space;
	fct_flag['+'] = &handle_pos;
	fct_flag['-'] = &handle_neg;
	fct_flag['.'] = &handle_dot;
}

static void	setup_conv(t_fcts_conv *fct_conv)
{
	fct_conv['%'] = &handle_percent;
	fct_conv['$'] = &handle_fd;
	fct_conv['c'] = &handle_char;
	fct_conv['C'] = &handle_wchar;
	fct_conv['s'] = &handle_str;
	fct_conv['S'] = &handle_wstr;
	fct_conv['d'] = &handle_decimal;
	fct_conv['i'] = &handle_decimal;
	fct_conv['o'] = &handle_oct;
	fct_conv['u'] = &handle_uint;
	fct_conv['p'] = &handle_ptr;
	fct_conv['b'] = &handle_binaire;
}

int			setup_fcts(t_fcts_flag *fct_flag, t_fcts_conv *fct_conv)
{
	setup_flag(fct_flag);
	setup_conv(fct_conv);
	return (1);
}
