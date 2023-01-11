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

static t_bool	get_var(t_data *data, char *line)
{
	char	**res;
	char	*key;
	char	*value;
	int		i;

	res = split(line, ' ');
	if (!res)
		return (FALSE);
	i = find_char(res[0], '=');
	if (i == -1 || !i || i == str_len(res[0]) || size_tab(res) != 1)
		return (free_split(res, -1), FALSE);
	split_once(res[0], &key, &value, '=');
	add_item(&data->var, key, value);
	return (free_split(res, -1), TRUE);
}

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
	if (check_key(data->env, "PATH"))
		paths = split(get_value(data->env, "PATH"), ':');
	else
		paths = NULL;
	i = -1;
	while (pipes[++i])
		if (!add_back(&data->cmd, pipes[i], paths))
			return (free_split(paths, -1), free_cmds(&data->cmd), FALSE);
	data->n_pipes = --i;
	free_split(paths, -1);
	return (SUCCESS);
}
