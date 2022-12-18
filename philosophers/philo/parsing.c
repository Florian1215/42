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

static void	*free_env(t_env *env)
{
	free(env);
	return (NULL);
}

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static int	ft_atoi(char *nb, int *var, int max, int time)
{
	unsigned long int	res;
	int					i;

	res = 0;
	i = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
		res = res * 10 + nb[i++] - '0';
	if (!i || ft_strlen(nb) != i)
		return (1);
	if (res > (unsigned long)max)
		return (1);
	*var = (int)res * time;
	return (0);
}

t_env	*parsing(int ac, char **av)
{
	t_env	*env;

	if (ac != 4 && ac != 5)
		return (NULL);
	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	if (ft_atoi(av[0], &env->nb_philo, MAX_THREAD, 1))
		return (free_env(env));
	if (ft_atoi(av[1], &env->td, INT_MAX / USEC, USEC))
		return (free_env(env));
	if (ft_atoi(av[2], &env->te, INT_MAX / USEC, USEC))
		return (free_env(env));
	if (ft_atoi(av[3], &env->ts, INT_MAX / USEC, USEC))
		return (free_env(env));
	if (ac == 5)
	{
		if (ft_atoi(av[4], &env->must_eat, INT_MAX, 1))
			return (free_env(env));
	}
	else
		env->must_eat = -1;
	pthread_mutex_init(&env->mutex_print, NULL);
	return (env);
}
