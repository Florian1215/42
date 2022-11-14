/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:06:30 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/09 09:06:31 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first_lst;

	first_lst = NULL;
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst->content));
		if (!lst)
		{
			ft_lstclear(&first_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&first_lst, new_lst);
		lst = lst->next;
	}
	return (first_lst);
}
