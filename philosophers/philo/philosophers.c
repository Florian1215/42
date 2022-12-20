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

static void	live(t_philo *p)
{
	t_time	sleep_until;

	while (1)
	{
		print_state(p, THINK);
		pthread_mutex_lock(&p->env->p[get_fork(p, LEFT)].mutex_forks);
		print_state(p, FORK);
		pthread_mutex_lock(&p->env->p[get_fork(p, RIGHT)].mutex_forks);
		print_state(p, FORK);
		sleep_until = get_timestamp() + p->env->time[EAT];
		print_state(p, EAT);
		pthread_mutex_lock(&p->mutex_eat);
		p->eat_count += 1;
		p->eat_last = get_timedelta();
		pthread_mutex_unlock(&p->mutex_eat);
		work_usleep(sleep_until);
		pthread_mutex_unlock(&p->env->p[(p->n + 1) % p->env->nb].mutex_forks);
		pthread_mutex_unlock(&p->mutex_forks);
		sleep_until = get_timestamp() + p->env->time[SLEEP] - 10;
		print_state(p, SLEEP);
		work_usleep(sleep_until);
	}
}

static int	create_life(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->nb)
	{
		env->p[i].n = i;
		env->p[i].eat_count = 0;
		env->p[i].eat_last = 0;
		env->p[i].env = env;
		pthread_mutex_init(&env->p[i].mutex_forks, NULL);
		pthread_mutex_init(&env->p[i].mutex_eat, NULL);
	}
	i = -1;
	while (++i < env->nb)
		if (pthread_create(env->threads + i, NULL, (void *)live, env->p + i))
			return (0);
	return (1);
}

static int	is_alive(t_env *env)
{
	int				i;
	int				eat_enough;

	i = -1;
	while (++i < env->nb)
	{
		pthread_mutex_lock(&env->p[i].mutex_eat);
		if (env->p[i].eat_last + env->time[DIE] < get_timedelta())
			return (print_state(env->p + i, DIE), 0);
		pthread_mutex_unlock(&env->p[i].mutex_eat);
	}
	if (env->must_eat == -1)
		return (1);
	i = -1;
	while (++i < env->nb)
	{
		pthread_mutex_lock(&env->p[i].mutex_eat);
		eat_enough = env->p[i].eat_count < env->must_eat;
		pthread_mutex_unlock(&env->p[i].mutex_eat);
		if (eat_enough)
			return (1);
	}
	return (0);
}

static int	free_all(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->nb)
	{
		pthread_mutex_destroy(&env->p[i].mutex_forks);
		pthread_mutex_destroy(&env->p[i].mutex_eat);
	}
	i = -1;
	pthread_mutex_destroy(&env->mutex_print);
	while (++i < env->nb)
		if (pthread_detach(env->threads[i]))
			return (3);
	free(env);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	*env;

	env = parsing(--ac, ++av);
	if (!env)
	{
		printf("./philo number_of_philosophers time_to_die time_to_" \
			"eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (env->must_eat == 0)
		return (free(env), 0);
	if (!create_life(env))
		return (free(env), 2);
	while (is_alive(env))
		continue ;
	return (free_all(env));
}
