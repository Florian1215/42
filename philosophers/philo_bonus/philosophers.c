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

static void	is_alive(t_philo *p)
{
	int		eat_count;
	t_time	last_eat;

	while (1)
	{
		sem_wait(p->env->sem_eat);
		eat_count = p->eat_count;
		last_eat = p->eat_last;
		sem_post(p->env->sem_eat);
		if (last_eat + p->env->time[DIE] < get_timedelta())
		{
			print_state(p, DIE);
			exit(1);
		}
		if (p->env->must_eat != -1 && eat_count >= p->env->must_eat)
			exit(1);
		usleep(100);
	}
}

static void	live(t_philo *p)
{
	t_time	sleep_until;

	pthread_create(&p->threads_is_alive, NULL, (void *)is_alive, p);
	while (1)
	{
		print_state(p, THINK);
		sem_wait(p->env->sem_forks);
		print_state(p, FORK);
		sem_wait(p->env->sem_forks);
		print_state(p, FORK);
		sleep_until = get_timestamp() + p->env->time[EAT];
		print_state(p, EAT);
		work_usleep(sleep_until);
		sleep_until = get_timestamp() + p->env->time[SLEEP];
		sem_post(p->env->sem_forks);
		sem_post(p->env->sem_forks);
		sem_wait(p->env->sem_eat);
		p->eat_count += 1;
		p->eat_last = get_timedelta();
		sem_post(p->env->sem_eat);
		print_state(p, SLEEP);
		work_usleep(sleep_until);
	}
}

static void	wail_and_kill(t_env *env, int n)
{
	int	i;
	int	status;

	if (n == -1)
	{
		i = -1;
		while (++i < env->nb)
		{
			waitpid(-1, &status, 0);
			if (status)
				break ;
		}
	}
	i = -1;
	while (++i < env->nb || (i <= n && n != -1))
		kill(env->pid[i], SIGKILL);
	sem_close(env->sem_eat);
	sem_close(env->sem_forks);
	sem_close(env->sem_print);
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
	}
	i = -1;
	get_timedelta();
	while (++i < env->nb)
	{
		env->pid[i] = fork();
		if (env->pid[i] == -1)
			return (wail_and_kill(env, i), 0);
		if (env->pid[i] == 0)
			live(env->p + i);
		usleep(100);
	}
	wail_and_kill(env, -1);
	return (1);
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
}
