/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:48:29 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/02 16:03:13 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd(char *cmd, char **env, int *pipe_fd, int n)
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

int	main(int ac, char **av, char **env)
{
	int		pid;
	int		pipe_fd[2];
	char	buffer[BUFSIZ + 1];

	if (check_args(--ac, ++av) == -1)
		return (0);
	if (pipe(pipe_fd) == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		return (2);
	cmd(av[1 + (pid == 0)], env, pipe_fd, (pid == 0));
}
