/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:50:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/08 10:50:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	parsing(t_data *data, char *line)
{
	char	**pipes;
	char	**paths;
	int		i;

	if (get_var(data, line))
		return (SUCCESS);
	pipes = split(line, '|');
	if (!pipes)
		return (ERROR);
	paths = split(get_value(data->env, "PATH"), ':');
	i = -1;
	while (pipes[++i])
		if (!add_back(data, pipes[i], paths))
			return (free_split(paths, -1), free_cmds(&data->cmd), FALSE);
	data->n_pipes = --i;
	free_split(paths, -1);
	return (SUCCESS);
}
