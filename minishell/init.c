/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:16:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/09 14:16:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_pids(t_data *data)
{
	int	*pids;

	if (data->pids != NULL)
		free(data->pids);
	pids = (int *)malloc(sizeof(int) * (data->n_pipes + 1));
	if (pids == NULL)
		exit(-1); // a modifier
	data->pids = pids;
}

void	init_pipes(t_data *data, t_cmd *head)
{
	int	**pipes;
	int	k;

	if (data->pipes != NULL)
		free_pipes(data->pipes, data->n_pipes);
	data->n_pipes = 1;
	while (head->next)
	{
		head = head->next;
		data->n_pipes++;
	}
	pipes = (int **)malloc(sizeof(int *) * data->n_pipes);
	if (pipes == NULL)
		exit(-2);
	k = 0;
	while (k < data->n_pipes)
	{
		pipes[k] = (int *)malloc(sizeof(int) * 2);
		if (pipes[k] == NULL)
			exit(-3); // a modifier
		if (pipe(pipes[k]) != 0)
			exit(-4); // a modifier
		k++;
	}
	data->pipes = pipes;
}

void	init_forks(t_data *data, t_cmd *commands)
{
	int	k;

	k = 0;
	while (k < data->n_pipes + 1)
	{
		data->pids[k] = fork();
		if (data->pids[k] == 0)
			execute(commands, k);
		else if (data->pids[k] == -1)
			exit(-1); // a modifier
		k++;
		commands = commands->next;
	}
}
