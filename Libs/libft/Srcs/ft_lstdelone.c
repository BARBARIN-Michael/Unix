/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:43:24 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/30 15:11:43 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list **alst, t_del del)
{
	if (*alst)
		(*del)((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
	alst = NULL;
}
