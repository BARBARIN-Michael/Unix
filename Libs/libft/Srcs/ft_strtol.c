/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 11:25:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/13 04:09:42 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

long int ft_strtol(char *line)
{
	long int	rslt;
	long int	*hexa;
	int			cmp;
	int			power;

	cmp = 0;
	power = 0;
	rslt = 0;
	hexa = (long int*)malloc(sizeof(long int) * ft_strlen(line));
	while (line[cmp])
	{
		if (line[cmp] >= 'A' && line[cmp] <= 'F')
			hexa[cmp] = line[cmp] + 10 - 'A';
		else if (line[cmp] >= '0' && line[cmp] <= '9')
			hexa[cmp] = line[cmp] - '0';
		cmp++;
	}
	while (--cmp >= 0)
	{
		rslt += hexa[cmp] * ft_pow(16, power);
		power++;
	}
	free(hexa);
	return (rslt);
}
