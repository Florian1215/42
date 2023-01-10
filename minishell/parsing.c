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

#include "minishell.h"

static t_builtins	get_builtin(char	*cmd)
{
	static char	*builtins[7] = {"echo", "cd", "pwd", "export", \
								"unset", "env", "exit"};
	int			i;

	i = -1;
	while (++i < NONE)
		if (!str_cmp(cmd, builtins[i]))
			return (i);
	return (NONE);
}

static t_bool	check_binary(char *binary_path)
{
	return (access(binary_path, F_OK) == -1 || access(binary_path, X_OK) == -1);
}

static char	*get_binary(char *cmd, char **paths)
{
	char	*res;
	int		i;

	if (!check_binary(cmd))
		return (cmd);
	if (!paths)
		return ((void)"Don't find paths", NULL);
	i = -1;
	while (paths[++i])
	{
		res = join_path(paths[i], cmd);
		if (!res)
			continue ;
		if (!check_binary(res))
			return (res);
		free(res);
	}
	return (NULL);
}

t_cmd	*parsing(char *line, char **paths)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = split(line, ' ');
	if (!cmd->args)
		return ((void)"Error", NULL);
	cmd->built_in = get_builtin(cmd->args[0]);
	if (cmd->built_in == NONE)
		cmd->cmd_path = get_binary(cmd->args[0], paths);
	cmd->next = NULL;
	return (cmd);
}
