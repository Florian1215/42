/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:47:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/11 09:47:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_cmds(t_cmd **cmd)
{
	t_cmd	*tmp;

	while (*cmd)
	{
		tmp = (*cmd)->next;
		free((*cmd)->cmd_path);
		free_split((*cmd)->args, -1);
		free(*cmd);
		*cmd = tmp;
	}
}

void	free_dict(t_dict **dict)
{
	t_dict	*tmp;

	while (*dict)
	{
		tmp = (*dict)->next;
		free((*dict)->value);
		free((*dict)->key);
		free(*dict);
		*dict = tmp;
	}
}

void	free_pipes(int **pipes, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	free_split(char **split, int i)
{
	if (!split)
		return ;
	if (i == -1)
	{
		i = 0;
		while (split[i])
			i++;
		i--;
	}
	while (i >= 0)
		free(split[i--]);
	free(split);
}
