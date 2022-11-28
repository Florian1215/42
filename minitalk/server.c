/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:21:38 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/28 14:03:51 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	test(int num)
{
	printf("int = %d\n", num);
	//write(STDOUT_FILENO, "test", 5);
}

void	handle(void)
{
	return ;
}

int	main(void)
{
	struct sigaction	sact;

	sact = {0};
	sact.sa_handler = handle;
	sigaction(SIGUSR1, &sact, NULL);
	signal(SIGUSR1, test);
	while (1)
	{
		printf("pid %d\n", getpid());
		sleep(10);
	}
}
