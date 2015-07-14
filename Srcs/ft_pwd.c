/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 17:05:58 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/29 18:10:15 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char		*ft_get_pwd(void)
{
	char *tab_len;

	tab_len = (char *)ft_memalloc(sizeof(char) * (DEFAULT_MAX_LENGHT_PATH + 1));
	tab_len = getcwd(tab_len, DEFAULT_MAX_LENGHT_PATH);
	return (tab_len);
}
