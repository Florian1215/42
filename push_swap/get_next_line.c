/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:24:34 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/15 10:24:34 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_nl(t_list *lst, int one_lst)
{
	int	size;
	int	i;

	size = 1;
	while (lst)
	{
		i = 0;
		while (lst->buff[i] && lst->buff[i] != '\n')
		{
			i++;
			size++;
		}
		if (lst->buff[i] == '\n' || (!one_lst && !lst->buff[i] && !lst->next))
			return (size);
		if (one_lst)
			break ;
		lst = lst->next;
	}
	return (-1);
}

char	*ft_add_res(t_list **lst)
{
	char	*res;
	int		i;
	int		j;
	int		loop;

	res = malloc(sizeof(char) * (ft_find_nl(*lst, 0) + 1));
	if (!res)
		return (0);
	i = 0;
	loop = 1;
	while (loop && *lst)
	{
		j = 0;
		while ((*lst)->buff[j] && loop)
		{
			if ((*lst)->buff[j] == '\n')
				loop = 0;
			else
				res[i++] = (*lst)->buff[j++];
		}
		ft_lstrm_first(lst);
	}
	return (res[i] = '\0', res);
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	int				read_bytes;
	char			*buff;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	read_bytes = 1;
	while (ft_find_nl(ft_lstlast(lst), 1) == -1 && read_bytes)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (0);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if ((!lst && !read_bytes) || read_bytes < 0)
		{
			free(buff);
			return (0);
		}
		buff[read_bytes] = '\0';
		ft_lstadd_back(&lst, ft_lstnew(buff));
	}
	return (ft_add_res(&lst));
}
