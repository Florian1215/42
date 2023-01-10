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

static char	**get_paths(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if (!str_n_cmp(envp[i], "PATH=", 5))
			return (split(envp[i] + 5, ':'));
	return (NULL);
}

void	cmd_(char *cmd, char **env, int *pipe_fd, int n)
{
	char	**args;
	char	*binary_path;

	close(pipe_fd[n]);
	dup2(pipe_fd[!n], !n);
	close(pipe_fd[!n]);
	args = ft_split(cmd);
	binary_path = get_binary(args, 0);
	if (!binary_path)
		return ;
	execve(binary_path, args, env);
	ft_free_split(args, -1);
}

int	main(int ac, char **av, char **envp)
{
	t_cmd	*cmd;
//	t_data	*data;
	char	**paths;

	(void)ac;
	paths = get_paths(envp);
	cmd = parsing(av[1], paths);
	free_split(paths, -1);
	if (!cmd)
		return (1);
	cmd_()
	free_split(cmd->args, -1);
	free(cmd->cmd_path);
	free(cmd);
	return (0);
}
