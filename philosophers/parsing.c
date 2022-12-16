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

//number_of_philosophers time_to_die time_to_eat time_to_sleep
// *[number_of_times_each_philosopher_must_eat]

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static void	ft_atoi(char *nb, int *var, int max)
{
	unsigned long int	res;
	int					i;

	res = 0;
	i = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
		res = res * 10 + nb[i++] - '0';
	if (!i || (i == 1 && sign == -1) || ft_strlen(nb) != i)
		return (error_(stack));
	if (res > max)
		return (error_(stack));
	*var = (int)res * sign;
}

s_env	*parsing(int ac, char **av)
{
	s_env	*env;

	if (ac != 4 && ac != 5)
		return (NULL);
	env = malloc(sizeof(s_env));
	if (!env)
		return (NULL);
	ft_atoi(av[0], &env->nb_philo, MAX_THREAD);
	ft_atoi(av[1], &env->td, INT_MAX);
	ft_atoi(av[2], &env->te, INT_MAX);
	ft_atoi(av[3], &env->ts, INT_MAX);
	if (ac == 5)
		ft_atoi(av[4], &env->must_eat, INT_MAX);
	else
		env->must_eat = -1;
	env->start_time = gettimeofday();
	return (env);
}
