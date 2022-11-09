/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:57:49 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/19 21:30:25 by fguirama         ###   ########lyon.fr   */
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

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*last_ptr;

	new = ft_create_elem(data);
	if (!*begin_list)
		*begin_list = new;
	else
	{
		last_ptr = ft_list_last(*begin_list);
		last_ptr->next = new;
	}
}
