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

#include "get_next_line.h"

t_list	*ft_lstnew(char *buff)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

void	ft_lstrm_first(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*next;
	int		st;
	int		i;

	tmp = *begin_list;
	printf("%d\n", ft_find_nl(tmp));
	if (ft_find_nl(tmp) == -1)
	{
		printf("remove lst  !");
		*begin_list = tmp->next;
		free(tmp->buff);
		free(tmp);
	}
	else
	{
		//printf("-|%s|-\n", tmp->buff);
		st = ft_find_nl(tmp) + 1;
		i = 0;
		while (tmp->buff[st])
			tmp->buff[i++] = tmp->buff[st++];
		tmp->buff[i] = '\0';
		//printf("-|%s|-\n", tmp->buff);
	}
}
