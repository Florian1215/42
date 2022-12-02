/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:03:54 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/02 16:17:40 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	get_len_file(int fd)
{
	size_t	len;
	int		read_state;

	len = 0;
	while (1)
	{
		read_state = read(fd, NULL, 100);
		if (read_state == 0)
			return (len);
		if (read_state == -1)
			return (-1);
		len += read_state;
	}
}

void	cpy_read(char *str, int fd)
{
	size_t	i;
	int		read_state;

	i = 0;
	read_state = 1;
	while (read_state)
	{
		read_state = read(fd, str + i, 100);
		if (read_state == -1)
			return (-1);
		i += read_state;
	}
}

char	*read_file(char *path)
{
	int		fd_file;
	size_t	len;
	char	*res;

	fd_file = open(path, O_RDONLY);
	if (fd_file == -1)
		return (NULL);
	len = get_len_file(fd_file);
	if (len == -1)
		return (NULL);
	res = malloc(len * sizeof(int));
	if (!res)
		return (NULL);
	cpy_read(res, fd_file);
	return (res);
}
