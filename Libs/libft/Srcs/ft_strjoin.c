/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 20:07:09 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/29 18:54:12 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = ft_memalloc(sizeof(char) * (len_s1 + len_s2 + 1));
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*str;
	int		len_s1;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	str = ft_memalloc(sizeof(char) * (len_s1 + n + 1));
	ft_strcat(str, s1);
	ft_strncat(str, (char *)s2, n);
	return (str);
}

char	*ft_multi_strjoin(size_t nbr_elem, ...)
{
	va_list		ap;
	char		*s1;
	char		*s2;
	char		*tmp;
	int			freedom;

	freedom = 0;
	va_start(ap, nbr_elem);
	s1 = (char *)va_arg(ap, char *);
	tmp = NULL;
	while (--nbr_elem > 0)
	{
		if (tmp != NULL)
		{
			if (freedom == 1)
				free(s1);
			s1 = tmp;
			freedom = 1;
		}
		s2 = (char *)va_arg(ap, char *);
		tmp = ft_strjoin(s1, s2);
	}
	free(s1);
	va_end(ap);
	return (tmp);
}
