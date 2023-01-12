/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:13:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/09 14:13:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	close_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_pipes)
	{
		close(data->pipes[i][0]);
		close(data->pipes[i][1]);
		i++;
	}
	if (data->fd[IN] != -1)
		close(data->fd[IN]);
	if (data->fd[OUT] != -1)
		close(data->fd[OUT]);
}

void	execute_bt(t_data *data)
{
	static t_bool	(*bt_func[8])(t_data *data) = {NULL, NULL, \
		bt_cd, NULL, NULL, bt_echo, bt_pwd, NULL};

	bt_func[data->cmd->built_in](data);
}

void	execute(t_data *data, int i)
{
	char	**envp;

	if (i == 0 && data->fd[IN] != -1)
		dup2(data->fd[IN], STDIN_FILENO);
	else if (i != 0)
		dup2(data->pipes[i - 1][0], STDIN_FILENO);
	if (i == data->n_pipes && data->fd[OUT] != -1)
		dup2(data->fd[OUT], STDOUT_FILENO);
	else if (i != data->n_pipes)
		dup2(data->pipes[i][1], STDOUT_FILENO);
	close_all(data);
	if (data->cmd->cmd_path)
	{
		envp = get_env(data->env);
		execve(data->cmd->cmd_path, data->cmd->args, envp);
		free_split(envp, -1);
	}
	if (data->cmd->built_in != NONE)
		execute_bt(data);
	exit(0);
}
