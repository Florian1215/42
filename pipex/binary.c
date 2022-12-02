/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:15:30 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/01 14:48:24 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*check_binary(char *binary_path, char **args, int free_split)
{
	if (binary_path)
	{
		if (access(binary_path, F_OK) == -1 || access(binary_path, X_OK) == -1)
			free(binary_path);
		else
		{
			if (free_split)
				ft_free_split(args, -1);
			return (binary_path);
		}
	}
	return (NULL);
}

char	*get_binary(char **args, int free_split)
{
	char	*path;
	int		i;
	char	*res;

	if (!args)
		return (NULL);
	i = -1;
	while (++i < 2)
	{
		if (i % 2)
			path = "/usr/bin/";
		else
			path = "/bin/";
		res = check_binary(ft_strjoin(path, args[0]), args, free_split);
		if (res)
			return (res);
	}
	ft_free_split(args, -1);
	return (NULL);
}
