/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:57:05 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/31 17:57:06 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		ft_wh1(char *str, int i)
{
	int cpt;

	cpt = i;
	while (str[cpt] && str[cpt] != '\n' && (str[cpt] == ' ' || str[cpt] == '\t'
				|| str[cpt] == '\f' || str[cpt] == '\v' || str[cpt] == '\r'))
		cpt++;
	return (cpt);
}

int		ft_wh2(char *str, int j)
{
	int cpt;

	cpt = j;
	while (str[cpt] && str[cpt] != '\n' && str[cpt] != ' ' && str[cpt] != '>'
			&& str[cpt] != '<' && str[cpt] != '|' && str[cpt]
			!= '&' && str[cpt] != ';')
		cpt++;
	return (cpt);
}

int		ft_wh3(char *str, int j)
{
	int cpt;

	cpt = j;
	while (str[cpt] && str[cpt] != '"')
		cpt++;
	return (cpt);
}
