/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:02:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/07 11:02:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_data(t_data *data)
{
	data->fd_in = -1;
	data->fd_out = -1;
	data->pids = NULL;
	data->pipes = NULL;
	data->cmd = NULL;
}

static t_bool	prompt(t_data *data)
{
	char	*line;

	while (TRUE)
	{
		init_data(data);
//		line = readline("minishell> ");
//		add_history(line);
		line = "cd FREE | ls";
		if (!parsing(data, line))
			return (ERROR); // ERROR
		init_pids(data);
		init_pipes(data);
		init_forks(data);
		free_cmds(&data->cmd);
		break ;
	}
	return (SUCCESS);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	(void)ac;
	(void)av;
	data.env = init_env(envp);
	data.var = NULL;
	if (!data.env)
		return (1);
	if (!prompt(&data))
		return (2);
	free_dict(&data.env);
	free_dict(&data.var);
	return (0);
}
