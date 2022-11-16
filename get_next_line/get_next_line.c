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


char	*ft_calloc()
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < BUFFER_SIZE + 1)
		res[i++] = '\0';
	return (res);
}

int	ft_find_nl(t_list *lst, int one_lst)
{
	int	size;
	int	i;

	size = 0;
	while (lst)
	{
		i = 0;
		while (lst->buff[i])
		{
			if (lst->buff[i++] == '\n')
				return (size);
			size++;
		}
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
		while (loop && (*lst)->buff[j])
		{
			res[i] = (*lst)->buff[j++];
			printf("add char \"%c\"\n", res[i]);
			if (res[i++] == '\n')
				loop = 0;
		}
		ft_lstrm_first(lst);
	}
	if (!i)
		return (0);
	return (res[i] = '\0', res);
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	int				read_bytes;
	char			*buff;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	while (ft_find_nl(ft_lstlast(lst), 1) == -1 && read_bytes)
	{
		buff = ft_calloc();
		if (!buff)
			return (0);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0 || (!lst && !read_bytes))
		{
			free(buff);
			return (0);
		}
		buff[read_bytes] = '\0';
		ft_lstadd_back(&lst, ft_lstnew(buff));
		printf("read = %d - buff = %s - n = %d\n", read_bytes, buff, ft_find_nl(ft_lstlast(lst), 1));
	}
	return (ft_add_res(&lst));
}


int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	//printf("LINE = \"%s\"", get_next_line(fd));
	//return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("LINE = \"%s\"", line);
	}
}
