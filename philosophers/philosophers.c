#include "philosophers.h"

int	main(int ac, char **av)
{
	t_env	*env;

	env = parsing(--ac, ++av);
	if (env)
	{
		ft_printf("%d\n", env->start_time)
	}
}
