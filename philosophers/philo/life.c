/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:08:49 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/17 18:08:51 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	get_fork(t_philo *p, int *fork1, int *fork2)
{
	int	flag;

	if (p->n % 2)
	{
		if (p->env->nb_philo % 2)
			flag = 0;
		else
			flag = 1;
	}
	else
	{
		if (p->env->nb_philo % 2)
			flag = 1;
		else
			flag = 0;
	}
	if (flag)
	{
		*fork1 = (p->n + 1) % (p->env->nb_philo);
		*fork2 = p->n;
	}
	*fork1 = p->n;
	*fork2 = (p->n + 1) % (p->env->nb_philo);
}

//static int	get_fork(t_philo *p, int fork)
//{
//	if (fork ^ (p->env->nb_philo % 2 ^ p->n % 2))
//		return ((p->n + 1) % p->env->nb_philo);
//	return (p->n);
//}

static void	lock_forks(t_philo *p)
{
	int	fork1;
	int	fork2;

	get_fork(p, &fork1, &fork2);
	pthread_mutex_lock(p->env->mutex_forks + fork1);// + get_fork(p, 0));
	pthread_mutex_lock(p->env->mutex_forks + fork2);// + get_fork(p, 1));
	print_state(p, FORK);
	print_state(p, FORK);
}

static void	unlock_forks(t_philo *p)
{
	pthread_mutex_unlock(p->env->mutex_forks + ((p->n + 1) % p->env->nb_philo));
	pthread_mutex_unlock(p->env->mutex_forks + p->n);
}

void	life(t_philo *p)
{
	while (1)
	{
		lock_forks(p);
		print_state(p, EAT);
		p->eat_count++;
		p->eat_last = get_timedelta();
		usleep(p->env->te);
		print_state(p, SLEEP);
		unlock_forks(p);
		usleep(p->env->ts - 10);
		print_state(p, THINK);
	}
}
