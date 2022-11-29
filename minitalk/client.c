/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:21:40 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 15:08:11 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*to_binary(int nb)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * 9);
	if (!res)
		return (NULL);
	i = 8;
	while (--i >= 0)
	{
		res[i] = nb % 2 + '0';
		nb /= 2;
	}
	res[8] = '\0';
	return (res);
}

void	client(pid_t pid, char *str)
{
	int		i;
	char	*binary_char;
	char	j;

	i = 0;
	//cehck if char to big
	// remake convert binary
	while (!i || str[i - 1])
	{
		binary_char = to_binary(str[i]);
		j = 0;
		while (j < 8)
		{
			if (binary_char[j++] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(10000);
			//usleep(200);
		}
		printf("%c - %s\n", str[i], binary_char);
		i++;
		free(binary_char);
	}
}

int	main(int ac, char **av)
{
	client(atoi(av[1]), av[2]);
}
