/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:56:32 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/20 17:01:22 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *dest, char *src)
{
	char	*resultat;

	resultat = dest;
	while (*dest)
		++dest;
	while (*src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
	return (resultat);
}
