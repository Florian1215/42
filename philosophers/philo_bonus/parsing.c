/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:32:49 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/16 11:32:51 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static int	atoi_(char *nb, int *var)
{
	unsigned long int	res;
	int					i;

	res = 0;
	i = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
		res = res * 10 + nb[i++] - '0';
	if (!i || str_len(nb) != i)
		return (1);
	*var = (int)res;
	return (0);
}

int	parsing(t_env *env, int ac, char **av)
{
	if (ac != 4 && ac != 5)
		return (1);
	if (atoi_(av[0], &env->nb) || env->nb > MAX_THREAD)
		return (1);
	if (atoi_(av[1], env->time + DIE))
		return (1);
	if (atoi_(av[2], env->time + EAT))
		return (1);
	if (atoi_(av[3], env->time + SLEEP))
		return (1);
	if (ac == 5)
	{
		if (atoi_(av[4], &env->must_eat))
			return (1);
	}
	else
		env->must_eat = -1;
	sem_unlink("sem_forks");
	sem_unlink("sem_print");
	sem_unlink("sem_eat");
	env->sem_forks = sem_open("sem_forks", O_CREAT | O_EXCL, S_IRWXU, env->nb);
	env->sem_print = sem_open("sem_print", O_CREAT | O_EXCL, S_IRWXU, 1);
	env->sem_eat = sem_open("sem_eat", O_CREAT | O_EXCL, S_IRWXU, 1);
	return (0);
}
