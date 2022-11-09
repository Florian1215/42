/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:31:53 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/21 11:17:15 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_len_file(char *path)
{
	int		len;
	int		r;
	char	c;
	int		file;

	file = open(path, 0);
	if (file == -1)
		return (0);
	len = 0;
	r = 1;
	while (r)
	{
		r = read(file, &c, 1);
		if (r == -1)
			return (0);
		if (r)
			len++;
	}
	close(file);
	return (len);
}

char	*ft_read(int file, int len)
{
	int		i;
	char	*content;

	content = malloc(sizeof(char) * (len + 1));
	if (!content)
		return (0);
	i = 0;
	while (i < len)
	{
		if (read(file, &content[i], 1) == -1)
			return (0);
		i++;
	}
	content[i] = '\0';
	return (content);
}

char	*ft_read_file(char *path)
{
	char	*content;
	int		file;
	int		len;

	len = ft_len_file(path);
	if (!len)
		return (0);
	file = open(path, 0);
	if (file == -1)
		return (0);
	content = ft_read(file, len);
	if (!content)
		return (0);
	close(file);
	return (content);
}
