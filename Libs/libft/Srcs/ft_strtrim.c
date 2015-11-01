/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 23:29:47 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/23 17:21:49 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t		cmp_start;
	size_t		cmp_end;
	char		*str;

	if (!s)
		return (NULL);
	cmp_start = 0;
	cmp_end = ft_strlen(s) - 1;
	if (*s == '\0')
		return (ft_strnew(0));
	if (!is_space(s[cmp_start]) && !is_space(s[cmp_end]))
		return (ft_strdup(s));
	while (is_space(s[cmp_start]))
		cmp_start++;
	while (is_space(s[cmp_end]) && cmp_end > cmp_start)
		cmp_end--;
	if (cmp_end < cmp_start)
		return (ft_strnew(0));
	str = ft_strsub(s, cmp_start, cmp_end - cmp_start + 1);
	return (str);
}
