/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:21:40 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/27 23:05:11 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (kill(pid, SIGUSR1))
	{
		while (str[i])
		{
			write(pid, str + i, 1);
			i++;
			usleep(15000);
		}
	}
}

int	main(int ac, char **av)
{
	client(atoi(av[1]), av[2]);
}
