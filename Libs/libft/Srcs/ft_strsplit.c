/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:25:09 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 18:50:11 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		is_carac(char str, char c)
{
	if (str == c)
		return (1);
	return (0);
}

static char		**ft_create_tab(int len)
{
	char	**str;

	str = (char **)malloc(sizeof(char *) * len);
	if (str)
		return (str);
	return (NULL);
}

int				ft_count_split(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (is_carac(str[i], c))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_carac(str[i], c))
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		k;
	int		len;

	if (!s)
		return (NULL);
	len = ft_count_split((char *)s, c);
	i = 0;
	j = 0;
	ret = ft_create_tab(len + 1);
	while (s[i])
	{
		while (is_carac(s[i], c))
			i++;
		k = i;
		while (s[i] && !is_carac(s[i], c))
			i++;
		if (j != len)
			ret[j++] = ft_strsub(s, k, (i - k));
	}
	ret[len] = NULL;
	return (ret);
}

char			**ft_nstrsplit(char const *s, char c, int len)
{
	char	**ret;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	ret = ft_create_tab(len + 1);
	while (s[i])
	{
		while (is_carac(s[i], c))
			i++;
		k = i;
		while (s[i] && !is_carac(s[i], c))
			i++;
		if (j != len)
			ret[j++] = ft_strsub(s, k, (i - k));
	}
	ret[len] = NULL;
	return (ret);
}
