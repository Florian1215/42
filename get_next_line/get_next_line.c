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

char	*ft_calloc(void)
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

	size = 0 + (lst && lst->buff[0] == '\n');
	while (lst)
	{
		i = 0;
		while (lst->buff[i] && lst->buff[i] != '\n')
		{
			i++;
			size++;
		}
		if (lst->buff[i] == '\n')// || (!lst->buff[i] && !lst->next && one_lst))
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
	//printf("size malloc %d\n", ft_find_nl(*lst, 0) + 1);
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
		ft_lstrm_first(lst);
	}
	if (!i)
	{
		free(res);
		return (0);
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
	printf("while %d\n", ft_find_nl(ft_lstlast(lst), 1) == -1 && read_bytes);
	while (ft_find_nl(ft_lstlast(lst), 1) == -1 && read_bytes)
	{
		buff = ft_calloc();
		if (!buff)
			return (0);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		printf("read %d\n", read_bytes);
		if ((!lst && !read_bytes) || read_bytes < 0)
		{
			free(buff);
			return (0);
		}
		buff[read_bytes] = '\0';
		ft_lstadd_back(&lst, ft_lstnew(buff));
		//printf("read = %d - buff = %s - nl = %d - bool %d\n", read_bytes, buff, ft_find_nl(ft_lstlast(lst), 1), ft_find_nl(ft_lstlast(lst), 1) == -1 && read_bytes);
	}
	return (ft_add_res(&lst));
}

///*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY);
	//line = get_next_line(fd);
	//printf("LINE = \"%s\"", line);
	//free(line);
	//return (0);
	while (1)
	{
		line = get_next_line(fd);
		printf("LINE = \"%s\"\n", line);
		if (!line)
			break ;
		free(line);
	}
}
//*/
