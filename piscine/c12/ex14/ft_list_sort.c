/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:28:42 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/19 11:28:44 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_merge(t_list *l, t_list *m, int (*cmp)())
{
	if (!l)
		return (m);
	if (!m)
		return (l);
	if (cmp(l->data, m->data) > 0)
	{
		m->next = ft_merge(l, m->next, cmp);
		return (m);
	}
	l->next = ft_merge(l->next, m, cmp);
	return (l);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*prev;
	t_list	*next;

	if (!*begin_list || !(*begin_list)->next)
		return ;
	prev = *begin_list;
	next = prev->next;
	while (next && next->next)
	{
		prev = prev->next;
		next = next->next;
	}
	next = prev->next;
	prev->next = NULL;
	ft_list_sort(&(*begin_list), cmp);
	ft_list_sort(&next, cmp);
	*begin_list = ft_merge(*begin_list, next, cmp);
}
