/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:26:29 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/19 11:26:31 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*first;
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	while ((*begin_list)->next)
	{
		next = (*begin_list)->next;
		(*begin_list)->next = prev;
		prev = *begin_list;
		*begin_list = next;
	}
	(*begin_list)->next = prev;
}
