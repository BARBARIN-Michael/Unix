/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:57:19 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/31 17:57:20 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int		op_multi(char *str)
{
	if (str[0] == '>' && str[1] == '>')
		return (o_red_dr);
	else if (str[0] == '<' && str[1] == '<')
		return (o_red_dl);
	else if (str[0] == '&' && str[1] == '&')
		return (o_and_d);
	else if (str[0] == '|' && str[1] == '|')
		return (o_pipe_d);
	else if (str[0] == '>' && str[1] == '&')
		return (o_red_e);
	else if (str[0] == '<' && str[1] == '&')
		return (o_undef);
	else if (str[0] == '&' && str[1] == '>')
		return (o_undef);
	else if (str[0] == '&' && str[1] == '<')
		return (o_undef);
	return (-1);
}

static int		op_simple(char *str)
{
	if (str[0] == ';')
		return (o_multi);
	else if (str[0] == '>' && str[1] != '>')
		return (o_red_r);
	else if (str[0] == '<' && str[1] != '<')
		return (o_red_l);
	else if (str[0] == '&' && str[1] != '&')
		return (o_undef);
	else if (str[0] == '|' && str[1] != '|')
		return (o_pipe);
	return (-1);
}

int				ft_which_op(char *str)
{
	int		ret;

	ret = 0;
	if (str[1])
	{
		ret = op_multi(str);
		if (ret == -1)
			ret = op_simple(str);
		return (ret != -1 ? ret : o_string);
	}
	return (o_string);
}
