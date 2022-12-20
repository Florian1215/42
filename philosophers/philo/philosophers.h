/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:03:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/16 12:03:06 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# define MAX_THREAD 200

typedef unsigned long long int	t_time;
typedef enum e_state			t_state;
typedef enum e_side				t_side;
typedef struct s_env			t_env;
typedef struct s_philo			t_philo;

enum e_side
{
	LEFT,
	RIGHT,
};

enum e_state
{
	DIE,
	EAT,
	SLEEP,
	THINK,
	FORK,
};

struct s_philo
{
	int				n;
	int				eat_count;
	t_time			eat_last;
	pthread_mutex_t	mutex_forks;
	pthread_mutex_t	mutex_eat;
	t_env			*env;
};

struct s_env
{
	int				nb;
	int				time[3];
	int				must_eat;
	pthread_mutex_t	mutex_print;
	t_philo			p[MAX_THREAD];
	pthread_t		threads[MAX_THREAD];
};

t_env	*parsing(int ac, char **av);
t_time	get_timedelta(void);
t_time	get_timestamp(void);
void	print_state(t_philo *p, t_state state);
int		get_fork(t_philo *p, t_side side);
void	work_usleep(t_time until);

#endif
