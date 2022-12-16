
#ifndef PHILOSOPHER_H
# definde PHILOSOPHER_H

# include <pthread.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/time.h>

# define MAX_THREAD 8

typedef struct s_philo
{
	pthread_t	t;
	int 		n;
}		t_philo;

typedef struct s_env
{
	int		start_time;
	int 	nb_philo;
	int		td;
	int		te;
	int 	ts;
	int		must_eat;
	t_philo	p[8];
}		s_env;

s_env	*parsing(int ac, char **av);
void	ft_printf(const char *format, ...);

#endif