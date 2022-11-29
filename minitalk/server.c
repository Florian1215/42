/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:21:38 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 16:57:17 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle(int sig, siginfo_t *sig_info, void *context)
{
	static int	ct = 0;
	static int	res = 0;

	(void)sig_info;
	(void)context;
	ct++;
	if (sig == SIGUSR2)
		res |= 1 << (8 - ct);
	if (ct == 8)
	{
		if (!res)
		{
			ft_printf("\n");
			kill(sig_info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", res);
		res = 0;
		ct = 0;
	}
}

int	main(void)
{
	struct sigaction	s0;
	struct sigaction	s1;

	ft_printf("PID: %d\n", getpid());
	s0.sa_flags = SA_SIGINFO;
	s0.sa_sigaction = handle;
	sigaction(SIGUSR1, &s0, NULL);
	s1.sa_flags = SA_SIGINFO;
	s1.sa_sigaction = handle;
	sigaction(SIGUSR2, &s1, NULL);
	while (1)
		pause();
}
