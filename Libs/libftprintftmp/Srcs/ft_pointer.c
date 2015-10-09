/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 21:17:20 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/02 13:47:11 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*handle_ptr(va_list ap, t_opt *opt)
{
	char	*str;

	opt->opt_type = opt_z;
	str = ft_special(*opt, ap, BASE_16X, &ft_ntoa);
	return (str);
}
