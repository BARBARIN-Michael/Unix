/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 12:57:10 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/08 13:23:16 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_pow(int valeur, int power)
{
	int rslt;

	rslt = 1;
	if (power == 0)
		return (1);
	while (power)
	{
		rslt *= valeur;
		power--;
	}
	return (rslt);
}
