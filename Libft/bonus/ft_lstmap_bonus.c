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
	t_list	*prev_lst;
	t_list	*next;

	prev_lst = NULL;
	next = lst;
	while (next)
	{
		lst = next;
		new_lst = ft_lstnew((*f)(lst->content));
		new_lst->next = prev_lst;
		prev_lst = new_lst;
		(*del)(lst->content);
		next = lst->next;
		free(lst);
	}
	return (new_lst);
}
