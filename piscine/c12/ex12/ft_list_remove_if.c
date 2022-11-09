/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:28:12 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/25 17:08:05 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void
*data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*l;
	t_list	*prev;
	t_list	*next;

	l = *begin_list;
	prev = NULL;
	while (l)
	{
		next = l->next;
		if (!(*cmp)(l->data, data_ref))
		{
			if (prev)
				prev->next = l->next;
			else
				*begin_list = next;
			(*free_fct)(l->data);
			free(l);
		}
		else
			prev = l;
		l = next;
	}
}
