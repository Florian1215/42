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
		sem_wait(p->env->p[get_fork(p, LEFT)].sem_forks);
		print_state(p, FORK);
		sem_wait(p->env->p[get_fork(p, RIGHT)].sem_forks);
		print_state(p, FORK);
		sleep_until = get_timestamp() + p->env->time[EAT];
		print_state(p, EAT);
		work_usleep(sleep_until);
		sleep_until = get_timestamp() + p->env->time[SLEEP];
		sem_post(p->env->p[(p->n + 1) % p->env->nb].sem_forks);
		sem_post(p->sem_forks);
		sem_wait(p->sem_eat);
		p->eat_count += 1;
		p->eat_last = get_timedelta();
		sem_post(p->sem_eat);
		print_state(p, SLEEP);
		work_usleep(sleep_until);
	}
}

static int	create_life(t_env *env)
{
	int	i;

	sem_unlink("print");
	env->sem_print = sem_open("print", O_CREAT | O_EXCL);
	i = -1;
	while (++i < env->nb)
	{
		sem_unlink("eat");
		sem_unlink("forks");
		env->p[i].n = i;
		env->p[i].eat_count = 0;
		env->p[i].eat_last = 0;
		env->p[i].env = env;
		env->p[i].sem_forks = sem_open("forks", O_CREAT | O_EXCL);
		env->p[i].sem_eat = sem_open("eat", O_CREAT | O_EXCL);
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
		sem_wait(env->p[i].sem_eat);
		if (env->p[i].eat_last + env->time[DIE] < get_timedelta())
		{
			print_state(env->p + i, DIE);
			exit(0);
		}
		sem_post(env->p[i].sem_eat);
	}
	if (env->must_eat == -1)
		return (1);
	i = -1;
	while (++i < env->nb)
	{
		sem_wait(env->p[i].sem_eat);
		eat_enough = env->p[i].eat_count < env->must_eat;
		sem_post(env->p[i].sem_eat);
		if (eat_enough)
			return (1);
	}
	exit(0);
}

//static int	free_all(t_env *env)
//{
//	int	i;
//
//	i = -1;
//	sem_close(env->sem_print);
//	while (++i < env->nb)
//		if (pthread_detach(env->threads[i]) || sem_close(env->p[i].sem_forks) \
//				|| sem_close(env->p[i].sem_eat))
//			return (3);
//	return (0);
//}

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
	return (0);
}
