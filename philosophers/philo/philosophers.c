/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:09:28 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/17 18:09:30 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	create_life(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->nb_philo)
	{
		env->p[i].n = i;
		env->p[i].eat_count = 0;
		env->p[i].eat_last = 0;
		env->p[i].env = env;
		pthread_mutex_init(env->mutex_forks + i, NULL);
	}
	i = -1;
	while (++i < env->nb_philo)
		if (pthread_create(env->threads + i, NULL, (void *)life, env->p + i))
			return (0);
	return (1);
}

static int	islive(t_env *env)
{
	int				i;

	i = -1;
	while (++i < env->nb_philo)
		if (env->p[i].eat_last + env->td / USEC + 10 < get_timedelta())
			return (print_state(env->p + i, DIE), 0);
	return (1);
}

static	int	iseat(t_env *env)
{
	int	i;

	i = -1;
	if (env->must_eat == -1)
		return (1);
	while (++i < env->nb_philo)
		if (env->p[i].eat_count <= env->must_eat)
			return (0);
	return (1);
}

static int	free_all(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->nb_philo)
	{
		pthread_mutex_destroy(env->mutex_forks + i);
		if (pthread_detach(env->threads[i]))
			return (3);
	}
	pthread_mutex_destroy(&env->mutex_print);
	free(env);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	*env;

	env = parsing(--ac, ++av);
	if (!env)
	{
		ft_printf("./philo number_of_philosophers time_to_die time_to_" \
			"eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (!create_life(env))
		return (free(env), 2);
	while (islive(env) && iseat(env))
		continue ;
	return (free_all(env));
}
