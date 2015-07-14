/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_carac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:02:24 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/09 14:45:04 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_carac(char *str, int carac)
{
	int		count;
	char	*s1;

	count = 0;
	s1 = str;
	while (*s1)
	{
		if (*s1 == carac)
			count++;
		s1++;
	}
	return (count);
}
