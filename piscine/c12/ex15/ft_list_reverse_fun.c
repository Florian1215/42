/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:28:54 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/25 17:08:21 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	while (begin_list->next)
	{
		next = begin_list->next;
		begin_list->next = prev;
		prev = begin_list;
		begin_list = next;
	}
	begin_list->next = prev;
}
