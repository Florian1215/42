/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:21:40 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/02 16:33:39 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid;

static int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!(str[i] >= '0' && str[i++] <= '9'))
			return (0);
	return (6 > i && i > 0);
}

static void	ft_atoi(const char *str)
{
	g_pid = 0;
	while (*str >= '0' && *str <= '9')
		g_pid = g_pid * 10 + *str++ - '0';
}

static void	received_message(int sig, siginfo_t *sig_info, void *context)
{
	(void)sig;
	(void)context;
	if ((int)sig_info->si_pid == g_pid)
		ft_printf("Message received !\n");
	else
		ft_printf("Error: ");
}

static void	client(char *str)
{
	int		i;
	char	j;
	int		sleep;

	i = 0;
	while (!i || str[i - 1])
	{
		j = 8;
		while (--j >= 0)
		{
			if ((str[i] >> j) & 1)
				kill(g_pid, SIGUSR2);
			else
				kill(g_pid, SIGUSR1);
			sleep = 0;
			while (sleep++ < 10)
				usleep(10);
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
		ft_printf("./client PID_SERVEUR STRING_TO_PASS\n");
	else
	{
		ft_atoi(av[1]);
		client(av[2]);
	}
}
