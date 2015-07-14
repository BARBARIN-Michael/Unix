/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 18:13:13 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/30 10:35:35 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		ft_setup_pipeline(t_pipeline *pipeline)
{
	int		cmp;

	cmp = 0;
	while (cmp < o_empty)
	{
		pipeline[cmp] = &ft_str;
		cmp++;
	}
	pipeline[o_pipe] = &ft_pipe;
	pipeline[o_red_dl] = &ft_red_dl;
	pipeline[o_red_l] = &ft_red_l;
	pipeline[o_red_dr] = &ft_red_dr;
	pipeline[o_red_r] = &ft_red_r;
	return (1);
}
