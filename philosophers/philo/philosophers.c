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

	if (!(p->env->nb % 2) && p->n % 2)
		usleep(100);
	while (1)
	{
		print_state(p, THINK);
		pthread_mutex_lock(&p->mutex_forks);
		print_state(p, FORK);
		pthread_mutex_lock(&p->env->p[(p->n + 1) % p->env->nb].mutex_forks);
		print_state(p, FORK);
		sleep_until = get_timestamp() + p->env->time[EAT];
		print_state(p, EAT);
		work_usleep(sleep_until);
		sleep_until = get_timestamp() + p->env->time[SLEEP];
		pthread_mutex_unlock(&p->env->p[(p->n + 1) % p->env->nb].mutex_forks);
		pthread_mutex_unlock(&p->mutex_forks);
		pthread_mutex_lock(&p->mutex_eat);
		p->eat_count += 1;
		p->eat_last = get_timedelta();
		pthread_mutex_unlock(&p->mutex_eat);
		print_state(p, SLEEP);
		work_usleep(sleep_until);
	}
}

static int	create_life(t_env *env)
{
	int	i;

	if (pthread_mutex_init(&env->mutex_print, NULL))
		return (0);
	i = -1;
	get_timedelta();
	while (++i < env->nb)
	{
		env->p[i].n = i;
		env->p[i].eat_count = 0;
		env->p[i].eat_last = 0;
		env->p[i].env = env;
		if (pthread_mutex_init(&env->p[i].mutex_forks, NULL))
			return (0);
		if (pthread_mutex_init(&env->p[i].mutex_eat, NULL))
			return (0);
		if (pthread_create(env->threads + i, NULL, (void *)live, env->p + i))
			return (0);
	}
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
	if (pthread_mutex_destroy(&env->mutex_print))
		return (3);
	while (++i < env->nb)
		if (pthread_detach(env->threads[i]) || pthread_mutex_destroy \
		(&env->p[i].mutex_forks) || pthread_mutex_destroy(&env->p[i].mutex_eat))
			return (3);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	env;

	if (parsing(&env, --ac, ++av))
	{
		printf("./philo number_of_philosophers time_to_die time_to_" \
			"eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (env.must_eat == 0 || env.nb == 0)
		return (0);
	if (!create_life(&env))
		return (2);
	while (is_alive(&env))
		continue ;
	return (free_all(&env));
}
