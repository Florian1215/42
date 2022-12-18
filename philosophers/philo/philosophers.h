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
# include <stdarg.h>
# include <sys/time.h>
# include <stdlib.h>
# include <limits.h>

# define MAX_THREAD 8
# define USEC	1000

typedef enum e_state
{
	EAT,
	SLEEP,
	THINK,
	FORK,
	DIE,
}t_state;

typedef unsigned long long int	t_time;
typedef struct s_env			t_env;

typedef struct s_philo
{
	int		n;
	int		eat_count;
	t_time	eat_last;
	t_env	*env;
}t_philo;

struct s_env
{
	int				nb_philo;
	int				td;
	int				te;
	int				ts;
	int				must_eat;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_forks[MAX_THREAD];
	t_philo			p[MAX_THREAD];
	pthread_t		threads[MAX_THREAD];
};

t_env	*parsing(int ac, char **av);
void	ft_printf(const char *format, ...);
void	print_state(t_philo *p, t_state state);
t_time	get_timedelta(void);
void	life(t_philo *p);

#endif
