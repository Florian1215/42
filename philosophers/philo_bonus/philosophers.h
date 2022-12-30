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

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <unistd.h>

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
	int			n;
	int			eat_count;
	t_env		*env;
	t_time		eat_last;
	pthread_t	threads_is_alive;
};

struct s_env
{
	int			nb;
	int			time[3];
	int			must_eat;
	sem_t		*sem_eat;
	sem_t		*sem_print;
	sem_t		*sem_forks;
	t_philo		p[MAX_THREAD];
	pid_t		pid[MAX_THREAD];
};

int		parsing(t_env *env, int ac, char **av);
t_time	get_timedelta(void);
t_time	get_timestamp(void);
void	print_state(t_philo *p, t_state state);
void	get_fork(t_philo *p);
void	work_usleep(t_time until);

#endif
