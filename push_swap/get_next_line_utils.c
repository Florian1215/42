/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:24:31 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/15 10:24:31 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(char *buff)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(buff);
		return (NULL);
	}
	new->buff = buff;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst || !lst->next)
		return (lst);
	return (ft_lstlast(lst->next));
}

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	if (!*lst)
		*lst = new_lst;
	else
		ft_lstlast(*lst)->next = new_lst;
}

void	ft_lstrm_first(t_list **lst)
{
	t_list	*tmp;
	int		st;
	int		i;

	if (!*lst)
		return ;
	st = ft_find_nl(*lst, 1);
	if (st == -1 || !(*lst)->buff[st])
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->buff);
		free(tmp);
	}
	else
	{
		i = 0;
		while ((*lst)->buff[st])
			(*lst)->buff[i++] = (*lst)->buff[st++];
		(*lst)->buff[i] = '\0';
	}
}