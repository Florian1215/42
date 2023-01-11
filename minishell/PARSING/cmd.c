/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:48:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/11 10:48:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_builtins	get_builtin(char	*cmd)
{
	static char	*builtins[7] = {"env", "export", "cd", "unset", \
								"exit", "echo", "pwd"};
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

static t_cmd	*cmd_last(t_cmd *cmd)
{
	if (!cmd || !cmd->next)
		return (cmd);
	return (cmd_last(cmd->next));
}

static char	*get_binary(char *cmd, char **paths)
{
	char	*res;
	int		i;

	if (!check_binary(cmd))
		return (cmd);
	i = -1;
	while (paths[++i])
	{
		res = join_char(paths[i], cmd, '/');
		if (!res)
			continue ;
		if (!check_binary(res))
			return (res);
		free(res);
	}
	return (NULL);
}

t_bool	add_back(t_cmd **cmd, char *line, char **paths)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (ERROR);
	new->args = split(line, ' ');
	if (!new->args)
		return ((void)"Error", ERROR); // ERROR
	new->built_in = get_builtin(new->args[0]);
	if (new->built_in == NONE)
		new->cmd_path = get_binary(new->args[0], paths);
	else
		new->cmd_path = NULL;
	new->next = NULL;
	if (!*cmd)
		*cmd = new;
	else
		cmd_last(*cmd)->next = new;
	return (SUCCESS);
}
