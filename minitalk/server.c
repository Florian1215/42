/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:21:38 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 15:01:35 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*to_dec(int nb)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * 4);
	if (!res)
		return (NULL);
	i = 3;
	while (--i >= 0)
	{
		res[i] = nb % 10 + '0';
		nb /= 10;
	}
	res[3] = '\0';
	return (res);
}

void	handle(int sig, siginfo_t *info, void *context)
{
	static int	ct = 0;
	static int	res = 0;

	ct++;
	if (sig == SIGUSR1)
		ft_printf("0");
	else
	{
		ft_printf("1");
		res = res | 1 << (8 - ct);
	}
	if (ct == 8)
	{
		ft_printf("%c\n", res);
		res = 0;
		ct = 0;
	}
}

int	main(void)
{
	struct sigaction	s0;
	struct sigaction	s1;

	printf("pid %d\n", getpid());
	s0.sa_flags = SA_SIGINFO;
	s0.sa_sigaction = handle;
	sigaction(SIGUSR1, &s0, NULL);
	s1.sa_flags = SA_SIGINFO;
	s1.sa_sigaction = handle;
	sigaction(SIGUSR2, &s1, NULL);
	while (1)
		pause();
}


/*static int	counter = 0;
	static char	ch = 0;

	if (sig == SIGUSR2)
		ch = ch | 128 >> counter;
	printf("counter = %d - ch = %d - sig = %d", counter, ch, sig);
	counter++;
	if (counter == 8)
	{
		write(1, &ch, 1);
		ch = 0;
		counter = 0;
	}*/