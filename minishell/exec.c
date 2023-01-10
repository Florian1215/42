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

#include "minishell.h"

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
	close(data->fd_in);
	close(data->fd_out);
}

void	execute(t_cmd *cmd, int i)
{
	if (i == 0 && cmd->data->fd_in != NULL)
		dup2(cmd->data->(*fd_in), STDIN_FILENO);
	else if (i != 0)
		dup2(cmd->data->pipes[i - 1][0], STDIN_FILENO);
	if (i == cmd->data->n_pipes && cmd->data->fd_out != NULL)
		dup2(cmd->data->(*fd_out), STDOUT_FILENO);
	else if (i != cmd->data->n_pipes)
		dup2(cmd->data->pipes[i][1], STDOUT_FILENO);
	close_all(cmd->data);
	if (cmd->cmd_path != NULL)
		execve(cmd->cmd_path, cmd->args, cmd->data->envp);
	else
		put_str_nl("message d'erreur", STDERR_FILENO);
}
