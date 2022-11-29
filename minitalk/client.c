/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:21:40 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 16:57:35 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isnumber(char *str)
{
	while (*str)
		if (!(*str >= '0' && *str++ <= '9'))
			return (0);
	return (1);
}

static void	received_message(int sig, siginfo_t *sig_info, void *context)
{
	(void)sig;
	(void)sig_info;
	(void)context;
	ft_printf("Message received !");
}

static void	client(pid_t pid, char *str)
{
	int		i;
	char	j;

	i = 0;
	while (!i || str[i - 1])
	{
		j = 8;
		while (--j >= 0)
		{
			if ((str[i] >> j) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sign;

	sign.sa_flags = SA_SIGINFO;
	sign.sa_sigaction = received_message;
	sigaction(SIGUSR1, &sign, NULL);
	if (ac != 3 || !ft_isnumber(av[1]))
		ft_printf("./client [pid] [string]\n");
	else
		client(atoi(av[1]), av[2]);
}
