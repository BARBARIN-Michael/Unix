/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:42:39 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 18:45:54 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		next_sync_lst(t_list **lst1, t_list **lst2)
{
	if (lst1 && lst2)
	{
		*lst1 = (*lst1)->next;
		*lst2 = (*lst2)->next;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list		*lst_new;
	t_list		*lst_tmp;
	t_list		*lst_or;

	lst_new = NULL;
	lst_or = NULL;
	while (lst)
	{
		if (!lst_new)
		{
			lst_tmp = f(lst);
			if (!(lst_new = ft_lstnew(lst_tmp->content, lst_tmp->content_size)))
				return (NULL);
			lst_or = lst_new;
			lst = lst->next;
			continue ;
		}
		lst_tmp = f(lst);
		lst_new->next = ft_lstnew(lst_tmp->content, lst_tmp->content_size);
		if (!lst_new->next)
			return (NULL);
		next_sync_lst(&lst, &lst_new);
	}
	return (lst_or);
}
