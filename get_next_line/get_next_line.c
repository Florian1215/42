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

int	ft_find_nl(t_list *lst)
{
	int	size;
	int	i;
	int	nl;

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
		lst = lst->next;
	}
	return (-1);
}

char	*ft_add_res(t_list *lst)
{
	char	*res;
	int		i;
	int		j;
	int		loop;

	res = malloc(sizeof(char) * (ft_find_nl(lst) + 1));
	if (!res)
		return (0);
	i = 0;
	loop = 1;
	while (loop && lst)
	{
		j = 0;
		while (lst->buff[j])
		{
			res[i] = lst->buff[j++];
			printf("char = '%c'\n", res[i]);
			if (res[i++] == '\n')
			{
				loop = 0;
				break ;
			}
		}
		lst = ft_lstrm_first(lst);
	}
	if (!i)
		return (0);
	res[i] = '\0';
	return (res);
}

void	ft_printlst(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("list %d = %s\n", i, lst->buff);
		i++;
		lst = lst->next;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	int				read_bytes;
	char			*buff;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	while (ft_find_nl(ft_lstlast(lst)) == -1 && read_bytes)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (0);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		printf("AAA");
		if (read_bytes < 0 || (!lst && !read_bytes))
		{
			free(buff);
			return (0);
		}
		buff[read_bytes] = '\0';
		printf("AAA");
		ft_lstadd_back(&lst, ft_lstnew(buff));
		printf("readbyte = %d - find %d - buff %s\n", read_bytes, ft_find_nl(ft_lstlast(lst)), ft_lstlast(lst)->buff);
		ft_printlst(lst);
	}
	return (ft_add_res(lst));
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	printf("\n\nline = %s", get_next_line(fd));
	return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("line = %s", line);
	}
}
