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
	while (get_timestamp() < until)
		usleep(10);
}

void	print_state(t_philo *p, t_state state)
{
	static char	*states[5] = {"died", "is eating", "is sleeping", \
								"is thinking", "has taken a fork"};
	static char	*colors[5] = {"30", "31", "93", "94", "96"};

	sem_wait(p->env->sem_print);
	printf("\033[37m%-6llu\033[0m %d \033[%sm%s\033[0m\n", get_timedelta(), \
		p->n + 1, colors[state], states[state]);
	if (state != DIE)
		sem_post(p->env->sem_print);
}
