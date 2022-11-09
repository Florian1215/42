/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:25:55 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/19 21:43:23 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list || !begin_list->next)
		return (begin_list);
	return (ft_list_last(begin_list->next));
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*new;
	t_list	*prev;

	i = 0;
	while (i < size)
	{
		new = ft_create_elem(strs[i]);
		if (i == 0)
			new->next = NULL;
		else
			new->next = prev;
		prev = new;
		i++;
	}
	return (prev);
}
