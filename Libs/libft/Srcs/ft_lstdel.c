/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:00:05 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/30 15:11:06 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, t_del del)
{
	t_list	*lst;

	(*del)((*alst)->content, (*alst)->content_size);
	lst = (*alst)->next;
	while (lst)
	{
		(*del)(lst->content, lst->content_size);
		lst = lst->next;
	}
	ft_memdel((void **)alst);
}
