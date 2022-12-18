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

t_time	get_timestamp(void)
{
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	return ((timestamp.tv_sec * USEC) + (timestamp.tv_usec / USEC));
}

t_time	get_timedelta(void)
{
	static t_time	start = 0;

	if (!start)
		start = get_timestamp();
	return (get_timestamp() - start);
}

void	print_state(t_philo *p, t_state state)
{
	static char	*states[5] = {"is eating", "is sleeping", "is thinking", \
							"has taken a fork", "died"};

	pthread_mutex_lock(&p->env->mutex_print);
	ft_printf("%d %d %s\n", get_timedelta(), p->n, states[state]);
	pthread_mutex_unlock(&p->env->mutex_print);
}
