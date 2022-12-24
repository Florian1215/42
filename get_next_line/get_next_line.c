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

#include "get_next_line.h"

static int	find_nl(t_list *lst, int one_lst)
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

static int  lstadd_back(t_list **lst, char *buff)
{
    t_list	*new_lst;

    new_lst = malloc(sizeof(t_list));
    if (!new_lst)
        return (free(buff), 1);
    new_lst->buff = buff;
    new_lst->next = NULL;
    if (!*lst)
        *lst = new_lst;
    else
        lstlast(*lst)->next = new_lst;
    return (0);
}

static void	lstrm_first(t_list **lst)
{
    t_list	*tmp;
    int		st;
    int		i;

    if (!*lst)
        return ;
    st = find_nl(*lst, 1);
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

static char	*get_line(t_list **lst)
{
	char	*res;
	int		i;
	int		j;
	int		loop;

	res = malloc(sizeof(char) * (find_nl(*lst, 0) + 1));
	if (!res)
		return (0);
	i = 0;
	loop = 1;
	while (loop && *lst)
	{
		j = 0;
		while ((*lst)->buff[j] && loop)
		{
			res[i] = (*lst)->buff[j++];
			if (res[i++] == '\n')
				loop = 0;
		}
		lstrm_first(lst);
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
	while (find_nl(lstlast(lst), 1) == -1 && read_bytes)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if ((!lst && !read_bytes) || read_bytes < 0)
			return (free(buff), NULL);
		buff[read_bytes] = '\0';
        if (lstadd_back(&lst, buff))
            return (NULL);
	}
	return (get_line(&lst));
}
