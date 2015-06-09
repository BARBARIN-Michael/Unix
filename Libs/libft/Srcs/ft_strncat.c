/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:57:02 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 14:22:30 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include <unistd.h>

char		*ft_strncat(char *s1, char *s2, size_t n)
{
	char	*rslt;

	rslt = s1;
	while (*s1)
		s1++;
	while (n)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	return (rslt);
}

char		*ft_nstrncat(char *s1, char *s2, size_t ns1, size_t n)
{
	char	*rslt;

	rslt = s1;
	while (ns1)
	{
		s1++;
		ns1--;
	}
	while (n)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	return (rslt);
}
