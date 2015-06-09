/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 12:37:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 18:47:44 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_ceil(float a)
{
	return (int)(a + 1);
}

int ft_floor(float a)
{
	return (int)a;
}

int ft_round(float a)
{
	return (ft_ceil(a - 0.5) == ft_ceil(a) ? ft_ceil(a) : ft_floor(a));
}
