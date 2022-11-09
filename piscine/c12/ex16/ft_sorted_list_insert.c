/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:29:07 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/19 11:29:09 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;

	if (!*begin_list || (*cmp)(data, (*begin_list)->data) <= 0)
	{
		elem = ft_create_elem(data);
		if (!elem)
			return ;
		elem->next = *begin_list;
		*begin_list = elem;
	}
	else
		ft_sorted_list_insert(&(*begin_list)->next, data, cmp);
}
