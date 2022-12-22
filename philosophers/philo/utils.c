/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:08:54 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/17 18:08:56 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_fork(t_philo *p, t_side side)
{
	if (side ^ (p->env->nb % 2 ^ p->n % 2))
		return ((p->n + 1) % p->env->nb);
	return (p->n);
}

t_time	get_timestamp(void)
{
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	return ((timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000));
}

t_time	get_timedelta(void)
{
	static t_time	start = 0;

	if (!start)
		start = get_timestamp();
	return (get_timestamp() - start);
}

void	work_usleep(t_time until)
{
	while (get_timestamp() < until - 10)
		usleep(10);
}

void	print_state(t_philo *p, t_state state)
{
	static char	*states[5] = {"died", "is eating", "is sleeping", \
								"is thinking", "has taken a fork"};
 	static char	*colors[5] = {"31", "32", "33", "34", "36"};

	pthread_mutex_lock(&p->env->mutex_print);
	printf("%llu %d \033[1;%sm%s\033[0m\n", get_timedelta(), p->n + 1, colors[state], states[state]);
	if (state != DIE)
		pthread_mutex_unlock(&p->env->mutex_print);
}
