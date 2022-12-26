/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:32:49 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/16 11:32:51 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static int	ft_atoi(char *nb, int *var)
{
	unsigned long int	res;
	int					i;

	res = 0;
	i = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
		res = res * 10 + nb[i++] - '0';
	if (!i || ft_strlen(nb) != i)
		return (1);
	*var = (int)res;
	return (0);
}

int	parsing(t_env *env, int ac, char **av)
{
	if (ac != 4 && ac != 5)
		return (1);
	if (ft_atoi(av[0], &env->nb) || env->nb > MAX_THREAD)
		return (1);
	if (ft_atoi(av[1], env->time + DIE))
		return (1);
	if (ft_atoi(av[2], env->time + EAT))
		return (1);
	if (ft_atoi(av[3], env->time + SLEEP))
		return (1);
	if (ac == 5)
	{
		if (ft_atoi(av[4], &env->must_eat))
			return (1);
	}
	else
		env->must_eat = -1;
	get_timedelta();
	return (0);
}
